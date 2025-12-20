#include <stdio.h>
#include "array_store.h"
#include "linkedlist_store.h"

int main() {
    Login l1 = {"2025-01-01 10:00", "admin", "FAIL", "192.168.1.1"};
    Login l2 = {"2025-01-01 10:01", "admin", "FAIL", "192.168.1.1"};
    Login l3 = {"2025-01-01 10:02", "root", "SUCCESS", "10.0.0.5"};

    printf("=== ARRAY STORAGE ===\n");
    LoginArray arr;
    initArray(&arr, 2);
    insertArray(&arr, l1);
    insertArray(&arr, l2);
    insertArray(&arr, l3);
    printArray(&arr);
    freeArray(&arr);

    printf("\n=== LINKED LIST STORAGE ===\n");
    Node *head = NULL;
    head = insertNode(head, l1);
    head = insertNode(head, l2);
    head = insertNode(head, l3);
    printList(head);
    freeList(head);

    return 0;
}
