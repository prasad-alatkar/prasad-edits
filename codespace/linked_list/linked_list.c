#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/* Define structures here */ 
struct node {
    int data;
    struct node *next;
};

struct node *ll_add(struct node **, int);

void print_ll(struct node *ll) {
    while (ll != NULL) {
        printf("-[%d] ", ll->data);
        ll = ll->next;
    }
    printf("EOL ;; \n");
}

void ll_add_multiple(struct node **ll, int count, ...) {
    int i;

    if(ll == NULL) {
        printf("No nodes, this function needs initialized LL");
        return;
    }

    va_list args;
    va_start(args, count);

    for (i = 0; i < count; i++) {
        ll_add(ll, va_arg(args, int));
    }

    va_end(args);
    return;
}

struct node *ll_add(struct node ** ll, int data) {

    struct node *temp, *p, *follow, *head = NULL;
    if(ll == NULL) {
        /* Unexpected */
        return NULL;
    }

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    
    p = *ll;
    follow = NULL;
    head = *ll;
    while(p) {
        follow = p;
        p = p->next;
    }

    if (follow == NULL) {
        follow = temp;
        return temp;
    } else {
        follow->next = temp;        
    }
    return head;
}

struct node *reverse_ll(struct node *ll) {
    struct node *p, *q, *r;

    p = ll;
    r = NULL;
    while(p != NULL) {
        q = p;
        p = p->next;
        q->next = r;
        r = q;
    }
    return q;
}

int main() {
    // Write C code here
    struct node *linked_list = NULL;
    
    // First node
    /* This is okay but why too many times inconsistent mallocs?
    Instead, get the pointer back to have anchor on head pointer.
    linked_list = (struct node *)malloc(sizeof(struct node *));
    linked_list-> data = 2;
    linked_list->next = NULL;*/
    
    linked_list = ll_add(&linked_list, 8);
    linked_list = ll_add(&linked_list, 10);
    /* Should not matter the head returned, should it? */
    ll_add(&linked_list, 15);
    ll_add(&linked_list, 20);
    ll_add_multiple(&linked_list, 9, 18, 11, 59, 74, 19, 125, 200, 1000, 119);

    print_ll(linked_list);
    linked_list = reverse_ll(linked_list);
    print_ll(linked_list);
    return 0;
}