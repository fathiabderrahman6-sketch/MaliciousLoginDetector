#include "stack_tracker.h"

void initStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, int value) {
    if (s->top < MAX_STACK - 1) {
        s->failures[++s->top] = value;
    }
}

int countFailures(Stack *s) {
    int count = 0;

    for (int i = s->top; i >= 0; i--) {
        if (s->failures[i] == 0)
            count++;
        else
            break;
    }
    return count;
}
