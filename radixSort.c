#include <math.h>

#include "list.c"
int powInt(int base, int exponent) {
    int rslt = 1;
    for(int i = 0;i<exponent;i++) {
        rslt*=base;
    }
    return rslt;
}
int getValAt(int num, int level, int base) {
    return (num/(powInt(base,level))%base);
}
int getMax(int* ary, int size) {
    int max = ary[0];
    for(int i = 1;i<size;i++) {
        if(max<ary[i]) {
            max = ary[i];
        }
    }
    return max;
}
void radixSort(int* ary, int base, int size) {
    struct listOnList* newLists = malloc(sizeof(struct listOnList)*base);
    int count = ceil(log(getMax(ary,size)/log(base)));
    createLists(size+base+10);
    for(int ii = 0;ii<base;ii++) {
        newLists[ii] = createList();
    }
    int* newAry = ary;
    for(int i = 0;i<count;i++) {
        for(int ii = 0;ii<size;ii++) {
            add(&newLists[getValAt(newAry[ii],i,base)],newAry[ii]);
        }
        int* tmpAry = malloc(sizeof(int*)*size);
        int currentBucket = 0;
        for(int ii = 0;ii<size;ii++) {
            while(getSize(&newLists[currentBucket])==0) {
                currentBucket++;
            }
            
            tmpAry[ii] = rem(&newLists[currentBucket],0);
        }
        newAry = tmpAry;
    }
    for(int i = 0;i<size;i++) {
        ary[i] = newAry[i];
    }
}
