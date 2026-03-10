#include <stdio.h>
#include "list.h"

int main(void) {

    List* list = initList();

    addToList(list,900);
    addToList(list,100);
    addToList(list,400);
    addToList(list,200);
    addToList(list,300);
    addToList(list,890);
    addToList(list,990);
    addToList(list,750);

    printList(list);

    int value, value1;
    popFromList(list,&value);
    printf("popped int %d\n",value);

    printList(list);

    popFromList(list,&value1);
    printf("popped int %d\n",value1);

    printListReverse(list);

    clearList(list);
    printList(list);

    printf("%d + %d = %d\n",value,value1,value+value1);

    freeList(list);
    return 0;
}