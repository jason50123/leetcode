#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *reverse(struct ListNode **head){
    struct ListNode *next = NULL;
    struct ListNode *temp;
    while(*head){
        temp = malloc(sizeof(struct ListNode));
        temp -> val = (*head) ->val;
        temp -> next = next;
        next = temp;
        *head =(*head) -> next;
    }
    return temp;
}


struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode* newHead = head;
    if(head == NULL){
        return NULL;
    }
    if(head -> next == NULL){
        return head;
    }

    while(head ->next != NULL){
        if(head->next->val == left){
            reverse(head->next);
        }
        head = head ->next;
    }
    while(head ->next->val != NULL){
        if(head == right){
            reverse(head);
        }
        head = head ->next;
    }
    return newHead;
}

