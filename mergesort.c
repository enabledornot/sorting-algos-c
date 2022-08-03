#include <stdlib.h>
#include "mergesort.h"
static int* copyPartOfAry(int* ary, int a, int b) {
    int* newAry = malloc(sizeof(int)*(b-a));
    for(int i = 0;i<b-a;i++) {
        newAry[i] = ary[a+i];
    }
    return newAry;
}

static int* mergesortrec(int* ary, int a, int b) {
    int* newAry = copyPartOfAry(ary,a,b);
    if(b-a<2) {
        return newAry;
    }
    int split = (b-a)/2;
    int* ary0 = mergesortrec(newAry,0,split);
    int* ary1 = mergesortrec(newAry,split,b-a);
    int loc0 = 0;
    int loc1 = 0;
    for(int i = 0;i<b-a;i++) {
        if(loc0==split) {
            newAry[i] = ary1[loc1];
            loc1+=1;
        }
        else if(loc1==b-a-split) {
            newAry[i] = ary0[loc0];
            loc0+=1;
        }
        else if(ary0[loc0]<ary1[loc1]) {
            newAry[i] = ary0[loc0];
            loc0+=1;
        }
        else {
            newAry[i] = ary1[loc1];
            loc1+=1;
        }
    }
    free(ary0);
    free(ary1);
    return newAry;
}

void mergesort(int* ary, int size) {
    int* newar = mergesortrec(ary,0,size);
    for(int i = 0;i<size;i++) {
        ary[i] = newar[i];
    }
    free(newar);
}
