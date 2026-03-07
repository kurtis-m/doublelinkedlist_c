#include "list.h"

int main(void) {

    List* list = initList();

    for (int i = 0; i < 9; ++i) {
        addToList(list, i * 10 + 10);
    }

    printList(list);
    printListReverse(list);

    freeList(list);
    return 0;
}