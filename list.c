#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
int* prevList;
int* folloList;
int* dataList;
int topOfStack;
int listSize;
struct listOnList {
    int locOnList;
    int size;
} listo;
void createLists(int maxContents) {
    prevList = malloc(sizeof(int)*maxContents);
    folloList = malloc(sizeof(int)*maxContents);
    dataList = malloc(sizeof(void*)*maxContents);
    for(int i = 0;i<maxContents-1;i++) {
        prevList[i] = -1;
        folloList[i] = i+1;
    }
    prevList[maxContents-1] = -1;
    folloList[maxContents-1] = -1;
    listSize = maxContents;
}
void printList() {
    printf("\npointer=%d\n",topOfStack);
    for(int i = 0;i<listSize;i++) {
        printf("(%d) %d %d %d\n",i,prevList[i],dataList[i],folloList[i]);
    }
}
int getSize(struct listOnList* theList) {
    return theList->size;
}
int getEndOfList(struct listOnList* theList) {
    int starting = theList->locOnList;
    while(folloList[starting]!=-1) {
        starting = folloList[starting];
    }
    // printf("%d\n",starting);
    return starting;
}
int getLocOnList(struct listOnList* theList, int loc) {
    if(theList->size<loc) {
        printf("List out of bounds\n");
        return -1;
    }
    int cposs = 0;
    int cloc = folloList[theList->locOnList];
    while(cposs<loc) {
        cloc = folloList[cloc];
        cposs+=1;
    }
    return cloc;
}
int newFromStack() {
    int newLoc = topOfStack;
    topOfStack = folloList[topOfStack];
    folloList[newLoc] = -1;
    return newLoc;
}
void returnToStack(int pointer) {
    folloList[pointer] = topOfStack;
    topOfStack = pointer;
    dataList[pointer] = INT_MIN;
    prevList[pointer] = -1;
}
void add(struct listOnList* theList, int newElement) {
    int ending = getEndOfList(theList);
    int newLoc = newFromStack();
    theList->size +=1;
    folloList[ending] = newLoc;
    prevList[newLoc] = ending;
    dataList[newLoc] = newElement;
}
void insert(struct listOnList* theList, int newElement, int pos) {
    int firstEli = getLocOnList(theList,pos);
    int lastEli = folloList[firstEli];
    int newLoc = newFromStack();
    theList->size+=1;
    prevList[newLoc] = firstEli;
    folloList[newLoc] = lastEli;
    prevList[firstEli] = newLoc;
    folloList[lastEli] = newLoc;
    dataList[newLoc] = newElement;
}
int rem(struct listOnList* theList, int toRemove) {
    int remElement = getLocOnList(theList,toRemove);
    // printf("-%d\n",remElement);
    int prevElement = prevList[remElement];
    int nextElement = folloList[remElement];
    folloList[prevElement] = nextElement;
    prevList[nextElement] = prevElement;
    theList->size-=1;
    int rslt = dataList[remElement];
    returnToStack(remElement);
    return rslt;
}
int get(struct listOnList* theList, int toGet) {
    int poss = getLocOnList(theList, toGet);
    return dataList[poss];
}
int remLast(struct listOnList* theList) {
    return rem(theList,theList->size-1);
}
struct listOnList createList() {
    struct listOnList newList;
    newList.locOnList = newFromStack();
    newList.size = 0;
    dataList[newList.locOnList] = INT_MIN;
    folloList[newList.locOnList] = -1;
    return newList;
}