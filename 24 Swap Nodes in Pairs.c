#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head){
    if(head == NULL){
        return NULL;
    }
    struct ListNode* ptr_first = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* ptr_second = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    ptr_first = head; 
    ptr_second = head;

    if(ptr_first != NULL && ptr_first ->next != NULL){
        ptr_second = ptr_second ->next;
        if(ptr_second -> next != NULL){
            temp = ptr_second -> next;
        }else {
            head = ptr_second;
            ptr_second ->next = ptr_first;
            ptr_first -> next = NULL;
            return head;
        }
        head = ptr_second;
        ptr_first -> next = ptr_second ->next;
        ptr_second ->next = ptr_first;
        ptr_first = temp;
        ptr_second = temp;
    }
    while(ptr_first != NULL && ptr_first ->next != NULL){
        ptr_second = ptr_second ->next;
        if(ptr_second -> next != NULL){
            temp = ptr_second -> next;
        }else {
            ptr_second ->next = ptr_first;
            ptr_first -> next = NULL;
            return head;
        }
        ptr_first -> next = ptr_second ->next;
        ptr_second ->next = ptr_first;
        ptr_first = temp;
        ptr_second = temp;
    }




    if(ptr_first != NULL && ptr_first ->next != NULL){
        ptr_second = ptr_second ->next;
        if(ptr_second -> next != NULL){
            temp = ptr_second -> next;
        }else {
            head = ptr_second;
            ptr_second ->next = ptr_first;
            ptr_first -> next = NULL;
            return head;
        }
        head = ptr_second;
        while(temp->next!=NULL){
            ptr_first -> next = temp ->next;
            ptr_second -> next = ptr_first;
            ptr_first = ptr_first-> next;
            if(ptr_first->next == NULL){
                ptr_first ->next = temp;
                temp ->next = NULL;
                return head;
            }else if((ptr_first ->next) ->next == NULL){
                ptr_second = ptr_first ->next;
                ptr_first -> next = temp;
                temp ->next = ptr_second;
                ptr_second -> next = NULL;
                return head;
            }else{
                ptr_second = temp;
                temp = ptr_first ->next;
                ptr_first ->next = ptr_second;
                ptr_first = ptr_first -> next;
            }

            ptr_second = ptr_first ->next;
        }
        ptr_second ->next = ptr_first;
        ptr_first = temp;
        ptr_second = temp;
    }



    return head;
}