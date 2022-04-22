// #include "utils.c"


void moveUp(int* ary, int loc, int from) {
    for(int i = loc;i<from;i++) {
        swap(ary,i,from);
    }
}
void insertSortRec(int* ary, int a, int b) {
    if(a==b) {
        return;
    }
    for(int i = a-1;i>=0;i--) {
        if(ary[i]>=ary[i+1]) {
            swap(ary,i,i+1);
        }
    }
    insertSortRec(ary,a+1,b);
}
void insertSort(int* ary, int size) {
    insertSortRec(ary,0,size);
}