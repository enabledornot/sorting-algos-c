#include <stdlib.h>
#include "utils.h"
#include "quicksort.h"
static int getPivot(int* ary, int a, int b) {
    return ary[a];
}

static int* pivotpart(int* ary, int a, int b, int pivot) {
    int x = a;
    int y = a;
    int z = b;
    while(y!=z) {
        if(ary[y]<pivot) {
            swap(ary,x,y);
            x++;
            y++;
        }
        else if(ary[y]==pivot) {
            y++;
        }
        else {
            z--;
            swap(ary,y,z);
        }
    }
    int* returnInt = malloc(sizeof(int)*2);
    returnInt[0] = x;
    returnInt[1] = y;
    return returnInt;
}

static void quickSortRec(int* ary, int a, int b) {
    if(a==b) {
        return;
    }
    int* ploc = pivotpart(ary,a,b,getPivot(ary,a,b));
    quickSortRec(ary,a,ploc[0]);
    quickSortRec(ary,ploc[1],b);
    free(ploc);
}
void quickSort(int* ary, int size) {
    quickSortRec(ary,0,size);
}
