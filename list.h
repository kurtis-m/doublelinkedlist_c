#ifndef DOUBLELINKEDLIST_C_LIST_H
#define DOUBLELINKEDLIST_C_LIST_H

#include <stddef.h>

/**
 * Struct representing a Node of a double linked list with an integer as data
 */
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

/**
 * Struct representing a double linked list
 */
typedef struct List {
    Node* head;
    Node* tail;
    size_t length;
} List;

List* initList();
bool listIsEmpty(const List* list);
void addToList(List* list, int data);
bool popFromList(List* list, int* output);
void clearList(List* list);
void freeList(List* list);
void printList(const List* list);
void printListReverse(const List* list);
int* listToArray(const List* list);
List* arrayToList(const int* arr, size_t size);

#endif //DOUBLELINKEDLIST_C_LIST_H