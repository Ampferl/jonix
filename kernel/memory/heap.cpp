#include "heap.h"
#include "../paging/PageTableManager.h"
#include "../paging/PageFrameAllocator.h"

void* heapStart;
void* heapEnd;
HeapSegmentHeader* LastHeader;

HeapSegmentHeader* HeapSegmentHeader::split(size_t splitLength){
    return NULL;
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

void ExpandHeap(size_t length){

}
