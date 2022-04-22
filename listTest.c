#include "list.c"

int main() {
    createLists(50);
    printList();
    struct listOnList newList = createList();
    struct listOnList newList2 = createList();
    for(int i = 0;i<10;i++) {
        add(&newList,i);
        // add(&newList2,i+50);
    }
    add(&newList2,-50);
    printList();
    for(int i = 0;i<2;i++) {
        rem(&newList,0);
    }
    printList();
    printf("%d\n",get(&newList,0));
}