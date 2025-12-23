#ifndef QUEUE_SIMULATOR_H
#define QUEUE_SIMULATOR_H

#include "login.h"

#define MAX_QUEUE 100

typedef struct {
    Login data[MAX_QUEUE];
    int front;
    int rear;
} Queue;

// Fonctions
void initQueue(Queue *q);
int isEmpty(Queue *q);
int isFull(Queue *q);
void enqueue(Queue *q, Login login);
Login dequeue(Queue *q);

#endif
