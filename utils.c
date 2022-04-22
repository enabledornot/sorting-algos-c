void swap(int* ary, int a, int b) {
    // printf("%d,%d\n",a,b);
    int tmp = ary[a];
    ary[a] = ary[b];
    ary[b] = tmp;
}

int compareInts(int a,int b) {
    return a-b;
}
void display(int* ary,int size) {
    for(int i = 0;i<size;i++) {
        printf("%d,",ary[i]);
    }
    printf("\n\n");
}
