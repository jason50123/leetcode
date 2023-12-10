#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    if(head == NULL)
        return NULL;
    if(head ->next == NULL)
        return head;
    int count = 0;
    count = left -right;
    struct ListNode *break_left = head;
    struct ListNode *break_right = head;
    struct ListNode *newlist = head;
    struct ListNode *temp_prev = head;
    struct ListNode *temp_next = head;
    struct ListNode *temp_cur = head;
    struct ListNode *temp;
    struct ListNode *temp_start;
    struct ListNode *temp_end;
    temp -> next = head;
    //先擷取中間
    while(temp -> next != NULL){
        if(temp ->next -> val == left){
            break_left = temp -> next;
            temp_start = temp;
        }
        if(temp -> next -> val == right){
            break_right = temp -> next;
            if(break_right ->next != NULL){
                temp_end = break_right -> next;
            }
        }
        head = head ->next;
    }
    switch(count){
        case 0:
            newlist = break_left;
            break_left -> next = NULL;
            break;
        case 1:
            newlist = break_right;
            break_right -> next = break_left;
            break_left ->next = NULL;
        case 2:
            temp_prev = break_left;
            temp_cur = temp_prev ->next;
            temp_next = temp_cur ->next;
            temp_next -> next = temp_cur;
            temp_cur -> next = temp_prev;
            temp_prev -> next = NULL;
            newlist = temp_next;
        default :
            temp_prev = NULL;
            temp_cur = break_left;
            temp_next = temp_cur ->next;
            goto reverse_list;
    }

    reverse_list:
        while(temp_next -> next!= NULL && temp_next ->val == break_right ->val){
            temp_cur ->next = temp_prev;
            temp_prev = temp_cur;
            temp_cur = temp_next;
            temp_next = temp_next ->next;
        }
    temp_next -> next = temp_cur;
    newlist = temp_next;
    temp_start -> next = newlist;


    /* 
        *testing above said there will at least one node in this list
        *and the below is special case to solve first two node in list
    */
    
    if(temp_next -> next != NULL){
        temp_next = temp_next -> next;
    }else{
        temp_next -> next = temp_cur;
        temp_cur -> next = NULL;
        head = temp_next;
        return head;
    }
    temp_cur = temp_cur -> next;
    temp_prev -> next = NULL;
    temp_cur -> next = temp_prev;
    temp_prev = temp_cur;
    temp_cur = temp_next;
    while(temp_next ->next != NULL){
        temp_next = temp_next -> next;
        temp_cur ->next = temp_prev;
        temp_prev = temp_cur;
        temp_cur = temp_next;
    }
    temp_cur -> next = temp_prev;
    head = temp_cur;
    return head;
    

}