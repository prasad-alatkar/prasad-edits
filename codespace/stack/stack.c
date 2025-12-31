#include "stdio.h"
#include "stdlib.h"

/* Linked list based stack implementation. Quick *
 * It can be Array based as well.                *
 * PUSH, POP, isEmpty                            *
 ***************                                 */

struct node {
    int data;
    struct node *next;
};

void print_stack(struct node *top) {
    while (top) {
        printf("[%d] \n", top->data);
        top = top->next;
    }
}

struct node *pop(struct node *top) {
    if (top == NULL) {
        return NULL;
    }

    struct node *temp = top->next;
    free(top);
    return temp;
}

struct node * push(struct node *top, int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Mem Allocation failed!");
        return NULL;
    }

    temp->data = data;
    temp->next = top;
    return temp; 
}

int main() {
    struct node *stack = NULL;
    printf("*** - Stack ops - ***\n");
    stack = push(stack, 2);
    stack = push(stack, 5);
    stack = push(stack, 10);
    stack = push(stack, 20);
    stack = push(stack, 52);
    stack = push(stack, 72);
    print_stack(stack);
    stack = pop(stack);
    stack = pop(stack);
    stack = pop(stack);
    printf("*** - Stack ops - ***\n");
    print_stack(stack);

    return 0;
}