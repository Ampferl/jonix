#include "heap.h"
#include "../paging/PageTableManager.h"
#include "../paging/PageFrameAllocator.h"

void* heapStart;
void* heapEnd;
HeapSegmentHeader* LastHeader;

HeapSegmentHeader* HeapSegmentHeader::split(size_t splitLength){
    if(splitLength < 0x10) return NULL;
    int64_t splitSegmentLength = length - splitLength - (sizeof(HeapSegmentHeader));
    if(splitSegmentLength < 0x10) return NULL;

    HeapSegmentHeader* newSplitHeader = (HeapSegmentHeader*)((size_t) this + splitLength + sizeof(HeapSegmentHeader));
    next->last = newSplitHeader;
    newSplitHeader->next = next;
    next = newSplitHeader;
    newSplitHeader->last = this;
    newSplitHeader->length = splitSegmentLength;
    newSplitHeader->free = free;
    length = splitLength;

    if(LastHeader == this) LastHeader = newSplitHeader;
    return newSplitHeader;
}
    void HeapSegmentHeader::CombineForward(){
        if(next == NULL) return;
        if(!next->free) return;

        if(next == LastHeader) LastHeader = this;

        if(next->next != NULL){
            next->next->last = this;
        }

        next = next->next;

        length = length + next->length + sizeof(HeapSegmentHeader);
    }

    void HeapSegmentHeader::CombineBackward(){
        if(last != NULL && last->free) last->CombineForward();
    }

void InitializeHeap(void* heapAddress, size_t pageLength){
    void* pos = heapAddress;

    for(size_t i = 0; i < pageLength; i++){
        GlobalPageTableManager.MapMemory(pos, GlobalAllocator.RequestPage());
        pos = (void*)((size_t)pos + 0x1000);
    }

    size_t heapLength = pageLength * 0x1000;

    heapStart = heapAddress;
    heapEnd = (void*)((size_t) heapStart + heapLength);
    HeapSegmentHeader* startSegment = (HeapSegmentHeader*)heapAddress;
    startSegment->length = heapLength - sizeof(HeapSegmentHeader);
    startSegment->next = NULL;
    startSegment->last = NULL;
    startSegment->free = true;
    LastHeader = startSegment;
}

void* malloc(size_t size){
    if(size % 0x10 > 0){
        size -= (size % 0x10);
        size += 0x10;
    }

    if(size == 0) return NULL;

    HeapSegmentHeader* currentSegment = (HeapSegmentHeader*) heapStart;
    while(true){
        if(currentSegment->free){
            if(currentSegment->length > size){
                currentSegment->split(size);
                currentSegment->free = false;
                return (void*)((uint64_t)currentSegment + sizeof(HeapSegmentHeader));
            }
            if(currentSegment->length == size){
                currentSegment->free = false;
                return (void*)((uint64_t)currentSegment + sizeof(HeapSegmentHeader));
            }
        }
        if(currentSegment->next == NULL) break;
        currentSegment = currentSegment->next;
    }
    ExpandHeap(size);
    return malloc(size);
}


void free(void* address){
    HeapSegmentHeader* segment = (HeapSegmentHeader*)address - 1;
    segment->free = true;
    segment->CombineForward();
    segment->CombineBackward();
}

void ExpandHeap(size_t length){
    if(length % 0x1000){
        length -= length % 0x1000;
        length += 0x1000;
    }

    size_t pageCount = length / 0x1000;
    HeapSegmentHeader* newSegment = (HeapSegmentHeader*)heapEnd;

    for(size_t i = 0; i < pageCount; i++){
        GlobalPageTableManager.MapMemory(heapEnd, GlobalAllocator.RequestPage());
        heapEnd = (void*)((size_t)heapEnd + 0x1000);
    }
    newSegment->free = true;
    newSegment->last = LastHeader;
    LastHeader->next = newSegment;
    LastHeader = newSegment;
    newSegment->next = NULL;
    newSegment->length = length - sizeof(HeapSegmentHeader);
    newSegment->CombineBackward();
}
