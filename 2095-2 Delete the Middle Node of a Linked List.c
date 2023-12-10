#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
//

struct ListNode* deleteMiddle(struct ListNode* head){
    struct ListNode *ptr_odd = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode *ptr_even = (struct ListNode*) malloc(sizeof(struct ListNode));
    ptr_odd -> next = head;
    ptr_even = head;
    if(head->next == NULL){
        return NULL;
    }
    do{
        ptr_even = ptr_even ->next;
        if(ptr_even ->next != NULL){
            ptr_odd = ptr_odd -> next;
            ptr_even = ptr_even -> next;
        }else{
            ptr_odd = ptr_odd->next;
        }
        
    }while(ptr_even -> next != NULL);

    

    ptr_odd ->next = (ptr_odd->next) ->next;

    return head;
}