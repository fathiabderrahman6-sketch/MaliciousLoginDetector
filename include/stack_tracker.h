#ifndef STACK_TRACKER_H
#define STACK_TRACKER_H

#define MAX_STACK 10

typedef struct {
    int failures[MAX_STACK];
    int top;
} Stack;

void initStack(Stack *s);
void push(Stack *s, int value);
int countFailures(Stack *s);

#endif
