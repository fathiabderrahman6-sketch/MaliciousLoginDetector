#include <stdio.h>
#include "array_store.h"
#include "linkedlist_store.h"
#include "stack_tracker.h"

int main(void) {

    printf("=== ARRAY STORAGE ===\n");
    ArrayStore arr;
    initArray(&arr);
    addToArray(&arr, 10);
    addToArray(&arr, 20);
    printArray(&arr);

    printf("\n=== LINKED LIST STORAGE ===\n");
    LinkedList list;
    initList(&list);
    insertNode(&list, 5);
    insertNode(&list, 15);
    printList(&list);

    printf("\n=== STACK BRUTE FORCE DETECTION ===\n");
    Stack s;
    initStack(&s);

    push(&s, 0);
    push(&s, 0);
    push(&s, 0);

    int fails = countFailures(&s);

    printf("Consecutive failures: %d\n", fails);

    if (fails >= 3)
        printf("⚠️ USER MARKED AS SUSPICIOUS\n");
    else
        printf("User is normal\n");

    return 0;
}
