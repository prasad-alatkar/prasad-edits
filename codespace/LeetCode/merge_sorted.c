#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    
    struct ListNode *head = NULL, *temp1 = NULL, *temp2 = NULL, *temp = NULL;
    temp1 = list1;
    temp2 = list2;

    if (temp1 == NULL) return temp2;
    if (temp2 == NULL) return temp1;

    while ((temp1 != NULL) && (temp2 != NULL)) {
        if (temp1->val <= temp2->val) {
            if (head == NULL) {
                head = list1;
            }
                
            if (temp != NULL) {
                temp->next = temp1;
            }
            temp = temp1;
            temp1 = temp1->next;             
        } else {
            if (head == NULL) {
                head = list2;
            } 
            
            if (temp != NULL) {
                temp->next = temp2;
            }
            temp = temp2;
            temp2 = temp2->next;
        }
    }

    if (temp1 != NULL && temp != NULL) {
        
        temp->next = temp1;
    }
    if (temp2 != NULL && temp != NULL) {
        
        temp->next = temp2;
    }

    return head;
}