#include "queue_simulator.h"

// Initialisation
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

// Vérifier si vide
int isEmpty(Queue *q) {
    return q->rear < q->front;
}

// Vérifier si pleine
int isFull(Queue *q) {
    return q->rear == MAX_QUEUE - 1;
}

// Ajouter une requête
void enqueue(Queue *q, Login login) {
    if (!isFull(q)) {
        q->data[++q->rear] = login;
    }
}

// Retirer une requête
Login dequeue(Queue *q) {
    return q->data[q->front++];
}
