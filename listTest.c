#include "list.c"

int main() {
    createLists(50);
    printList();
    struct listOnList newList[5];
    for(int i = 0;i<5;i++) {
        newList[i] = createList();
    }
    for(int i = 0;i<5;i++) {
        for(int ii = 0;ii<5;ii++) {
            add(&newList[i],ii*ii);
        }
    }
    printList();
}