#include "list.h"

#include <stdio.h>
#include <stdlib.h>


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

void freeList(List* list) {
    clearList(list);
    free(list);
}

bool listIsEmpty(const List* list) {
    return list->length == 0;
}

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

void printList(const List* list) {
    for (const Node* current = list->head; current != NULL; current = current->next) {
        printf("%d ",current->data);
    }
    printf("length: %llu\n",list->length);
}

void printListReverse(const List* list) {
    for (const Node* current = list->tail; current != NULL; current = current->prev) {
        printf("%d ",current->data);
    }
    printf("length: %llu\n",list->length);
}