#include "utils.h"
#include "selectionsort.h"

static int selSortMin(int* ary, int a, int b) {
    int min = ary[a];
    int locOfMin = a;
    for(int i = a+1;i<b;i++) {
        if(ary[i]<min) {
            min = ary[i];
            locOfMin = i;
        }
    }
    return locOfMin;
}
static void selSortRec(int* ary, int a, int b) {
    if(a==b) {
        return;
    }
    int min = selSortMin(ary,a,b);
    swap(ary,a,min);
    selSortRec(ary,a+1,b);
}
void selSort(int* ary, int size) {
    selSortRec(ary,0,size);
}
