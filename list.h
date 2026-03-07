#ifndef DOUBLELINKEDLIST_C_LIST_H
#define DOUBLELINKEDLIST_C_LIST_H

#include <stddef.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
    size_t length;
} List;

List* initList();
bool listIsEmpty(const List* list);
void addToList(List* list, int data);
void clearList(List* list);
void freeList(List* list);
void printList(const List* list);
void printListReverse(const List* list);

#endif //DOUBLELINKEDLIST_C_LIST_H