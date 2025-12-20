#include <stdio.h>
#include <stdlib.h>
#include "linkedlist_store.h"

// Insertion en tête (O(1))
Node* insertNode(Node *head, Login login) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = login;
    newNode->next = head;
    return newNode;
}

// Affichage de la liste
void printList(Node *head) {
    int i = 0;
    while (head != NULL) {
        printf("[%d] %s | %s | %s | %s\n",
               i++,
               head->data.timestamp,
               head->data.username,
               head->data.status,
               head->data.ip_address);
        head = head->next;
    }
}

// Libération mémoire
void freeList(Node *head) {
    Node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
