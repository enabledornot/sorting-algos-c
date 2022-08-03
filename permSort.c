#include <stdlib.h>
#include "permSort.h"
static int fac(int num) {
    int rslt = 1;
    for(int i = 2;i<=num;i++) {
        rslt*=i;
    }
}
static int* recreateListWithout(int* list, int size, int noEli) {
    int* newList = malloc(sizeof(int)*(size-1));
    int count = 0;
    int altCount = 0;
    while(count<size) {
        if(count!=noEli) {
            newList[altCount] = list[count];
            altCount++;
        }
        count++;
    }
    return newList;
}
static int isSorted(int* ary, int size) {
    int prev = ary[0];
    for(int i = 1;i<size;i++) {
        if(prev>ary[i]) {
            return 0;
        }
        prev = ary[i];
    }
    return 1;
}

static int permSortRec(int* toAdd, int* currentAry, int sizeAdd, int sizeCurrent) {
    if(sizeAdd==0) {
        return isSorted(currentAry,sizeCurrent);
    }
    for(int i = 0;i<sizeAdd;i++) {
        int* tmpAdd = recreateListWithout(toAdd,sizeAdd,i);
        currentAry[sizeCurrent] = toAdd[i];
        if(permSortRec(tmpAdd,currentAry,sizeAdd-1,sizeCurrent+1)) {
            free(tmpAdd);
            return 1;
        }
        free(tmpAdd);
    }
    return 0;
}
void permSort(int* ary, int size) {
    int* sorted = malloc(sizeof(int)*size);
    permSortRec(ary,sorted,size,0);
    for(int i = 0;i<size;i++) {
        ary[i] = sorted[i];
    }
    free(sorted);
}