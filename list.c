#include "list.h"

#include <stdio.h>
#include <stdlib.h>


/**
 * Initializes an empty double linked list
 * @return Pointer to a double linked list
 */
List* initList() {
    List* list = malloc(sizeof(List));
    if (list == NULL) {
        fprintf(stderr, "Allocation error for List");
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

/**
 * Remove all nodes of the linked list
 * @param list Pointer to the list
 */
void clearList(List* list) {
    Node* current = list->head;

    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
}

/**
 * Frees the memory of the list and all of its nodes
 * @param list Pointer to the list
 */
void freeList(List* list) {
    clearList(list);
    free(list);
}

/**
 * Returns if the linked list is empty or not
 * @param list Pointer to the list
 * @return True or false if the list is empty
 */
bool listIsEmpty(const List* list) {
    return list->length == 0;
}

/**
 * Add a new node to the end of the list
 * @param list Pointer to the list
 * @param data Data of the new node as an integer
 */
void addToList(List* list, const int data) {
    Node* node = malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Allocation error for Node");
        return;
    }

    node->data = data;
    node->next = NULL;

    if (listIsEmpty(list)) {
        list->head = node;
        list->tail = node;
        node->prev = NULL;
    }
    else {
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    }
    ++list->length;
}

/**
 * Removes the first node of the list and points it to a new location
 * @param list Pointer to the list
 * @param output Pointer to the desired location of the integer data of the node
 * @return True or false if the node was successfully removed
 */
bool popFromList(List* list, int* output) {
    if (listIsEmpty(list)) {
        fprintf(stderr, "Can't pop from empty list");
        return false;
    }
    Node* oldhead = list->head;
    list->head = list->head->next;
    --list->length;

    if (listIsEmpty(list)) {
        list->tail = NULL;
    }
    else {
        list->head->prev = NULL;
    }
    *output = oldhead->data;
    free(oldhead);
    return true;
}

/**
 * Prints the data of the list to the console
 * @param list Pointer to the list
 */
void printList(const List* list) {
    printf("(");
    for (const Node* current = list->head; current != NULL; current = current->next) {
        printf(current->next == NULL ? "%d" : "%d, ", current->data);
    }
    printf(") length: %llu\n",list->length);
}

/**
 * Prints the data of the list to the console in reverse order
 * @param list Pointer to the list
 */
void printListReverse(const List* list) {
    printf("(");
    for (const Node* current = list->tail; current != NULL; current = current->prev) {
        printf(current->prev == NULL ? "%d" : "%d, ", current->data);
    }
    printf(") length: %llu (reversed)\n",list->length);
}

/**
 * Created an array of integers from a linked list
 * @param list Pointer to the linked list
 * @return Pointer to the new array of integers
 */
int* listToArray(const List* list) {
    int* arr = malloc(list->length * sizeof(int));
    int currentIndex = 0;

    for (const Node* current = list->head; current != NULL; current = current->next) {
        arr[currentIndex] = current->data;
        ++currentIndex;
    }
    return arr;
}
