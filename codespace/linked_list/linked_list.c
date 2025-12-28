#include <stdio.h>
#include <stdlib.h>

/* Define structures here */ 
struct node {
    int data;
    struct node *next;
};

void print_ll(struct node *ll) {
    while (ll != NULL) {
        printf("[%d] ", ll->data);
        ll = ll->next;
    }
}

void ll_add(struct node ** ll, int data) {

    struct node *temp, *p, *follow;
    if(ll == NULL) {
        printf("double ** NULL");
        return;
    }

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    
    p = *ll;
    follow = NULL;
    while(p) {
        follow = p;
        p = p->next;
    }

    if (!follow) {
        follow = temp;
    } else {
        follow->next = temp;        
    }
}

int main() {
    // Write C code here
    struct node *linked_list = NULL;
    
    // First node
    linked_list = (struct node *)malloc(sizeof(struct node *));
    linked_list-> data = 2;
    linked_list->next = NULL;
    
    ll_add(&linked_list, 8);
    ll_add(&linked_list, 10);
    ll_add(&linked_list, 15);
    ll_add(&linked_list, 20);
    
    print_ll(linked_list);
    return 0;
}