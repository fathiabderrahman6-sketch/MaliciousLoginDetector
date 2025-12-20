#ifndef LINKEDLIST_STORE_H
#define LINKEDLIST_STORE_H

#include "login.h"

// Noeud de la liste chaînée
typedef struct Node {
    Login data;
    struct Node *next;
} Node;

// Fonctions
Node* insertNode(Node *head, Login login);
void printList(Node *head);
void freeList(Node *head);

#endif
