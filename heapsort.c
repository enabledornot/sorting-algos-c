#include "utils.h"
#include "heapsort.h"
static int heapUp(int loc) {
    return (loc-1)/2;
}
static int heapLeft(int loc) {
    return (loc*2)+1;
}
static int heapRight(int loc) {
    return (loc*2)+2;
}
static void siftDown(int* ary, int loc, int size) {
    if(loc>=size) {
        return;
    }
    int maxloc = loc;
    int hl = heapLeft(loc);
    if(hl<size) {
        if(ary[maxloc]<ary[hl]) {
            maxloc = hl;
        }
    }
    int hr = heapRight(loc);
    if(hr<size) {
        if(ary[maxloc]<ary[hr]) {
            maxloc = hr;
        }
    }
    if(maxloc!=loc) {
        swap(ary,maxloc,loc);
        siftDown(ary,maxloc,size);
    }
}
static void heapify(int* ary, int size) {
    for(int i = size/2;i>=0;i--) {
        siftDown(ary,i,size);
    }
}
static void heapsortRec(int* ary, int size) {
    if(size==0) {
        return;
    }
    swap(ary,0,size-1);
    siftDown(ary,0,size-1);
    heapsortRec(ary,size-1);
}
void heapsort(int* ary, int size) {
    if(size==0) {
        return;
    }
    heapify(ary,size);
    heapsortRec(ary,size);
}