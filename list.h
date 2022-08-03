#ifndef SORTING_ALGOS_LIST
#define SORTING_ALGOS_LIST
struct listOnList {
    int locOnList;
    int size;
} listo;
void createLists(int maxContents);
void printList();
int getSize(struct listOnList* theList);
int getEndOfList(struct listOnList* theList);
int getLocOnList(struct listOnList* theList, int loc);
void add(struct listOnList* theList, int newElement);
void insert(struct listOnList* theList, int newElement, int pos);
int rem(struct listOnList* theList, int toRemove);
int get(struct listOnList* theList, int toGet);
int remLast(struct listOnList* theList);
struct listOnList createList();
#endif