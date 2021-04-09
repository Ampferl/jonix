#include "heap.h"
#include "../paging/PageTableManager.h"
#include "../paging/PageFrameAllocator.h"

void* heapStart;
void* heapEnd;
HeapSegmentHeader* LastHeader;

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
