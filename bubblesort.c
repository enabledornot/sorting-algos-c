#include "utils.h"
#include "bubblesort.h"
void bubbleSort(int* ary, int size) {
    for(int i = 0;i<size-2;i++) {
        for(int ii = 0;ii<size-1;ii++) {
            if(ary[ii]>ary[ii+1]) {
                swap(ary,ii,ii+1);
            }
        }
    }
}