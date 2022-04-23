#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "utils.c"
#include "selectionsort.c"
#include "insertionsort.c"
#include "bubblesort.c"
#include "mergesort.c"
#include "quicksort.c"
#include "heapsort.c"
#include "radixSort.c"
#include "permSort.c"

int *randArray(int size,int max);
int main() {
    srand(time(NULL));
    while(1) {
        int size = 0;
        int range = 0;
        int selectedAlgo = 0;
        while(0>=size) {
            printf("Enter array size:");
            scanf("%d",&size);
        }
        while(0>=range) {
            printf("Enter array integer range:");
            scanf("%d",&range);
        }
        while(selectedAlgo<1 || selectedAlgo>8) {
            printf("Select the sorting algorithm to be used from the list\n(1)selection sort\n(2)insertion sort\n(3)bubble sort\n(4)merge sort\n(5)quick sort\n(6)heap sort\n(7)radix Sort\n(8)perm Sort\nEnter:");
            scanf("%d",&selectedAlgo);
        }
        int* rnd = randArray(size,range);
        display(rnd,size);
        switch(selectedAlgo) {
            case 1:
                selSort(rnd,size);
                break;
            case 2:
                insertSort(rnd,size);
                break;
            case 3:
                bubbleSort(rnd,size);
                break;
            case 4:
                mergesort(rnd,size);
                break;
            case 5:
                quickSort(rnd,size);
                break;
            case 6:
                heapsort(rnd,size);
                break;
            case 7: {}
                int base = 0;
                printf("Enter base for radix sort (must be greater then 2):");
                scanf("%d",&base);
                radixSort(rnd,base,size);
                break;
            case 8:
                permSort(rnd,size);
                break;
        }
        permSort(rnd,size);
        display(rnd,size);
        free(rnd);
    }
}

int *randArray(int size,int max) {
    int* randomArray = malloc(sizeof(int)*size);
    for(int i = 0;i<size;i++) {
        randomArray[i] = rand()%max;
    }
    return randomArray;
}