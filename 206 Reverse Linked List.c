#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head){
    /*我們一開始傳進來要先判斷list是不是空以及整個linklist是不是只有一個點,
    如果是空的話我們就回傳NULL如果是以個點的話我們就直接回傳head pointer
    */
    if(head == NULL){
        return NULL;
    }
    if(head -> next == NULL){
        return head;
    }
    /*
        接下來我會宣告三個list node pointer,分別是來儲存前中後的三個位置的pointer
    */
    
    struct ListNode *temp_prev = head;
    struct ListNode *temp_next = head;
    struct ListNode *temp_cur = head;
    //接著會把next pointer先往前走
    temp_next = temp_next -> next;
    /* 
        *testing above said there will at least one node in this list
        *and the below is special case to solve first two node in list
    */
    /*
        往前走後先看他的next是不是null如果不是的話就在把next往前移到第三個點,但如果是null就表示整條linklist只有兩個點
        所以就把第一個點的next指到null,並把第二個點的next只到前面,並回傳第二個點的pointer 
    */
    if(temp_next -> next != NULL){
        temp_next = temp_next -> next;
    }else{
        temp_next -> next = temp_cur;
        temp_cur -> next = NULL;
        head = temp_next;
        return head;
    }
    /*
        接著就是三個點以上的情況,
        我們要先把第二個點(最後回傳的headpointer指向他),
        並且把第一個點指向NULL,
        再來就是把previous current 以及next 都往他們的next移動
    */
    temp_cur = temp_cur -> next;
    temp_prev -> next = NULL;
    temp_cur -> next = temp_prev;
    temp_prev = temp_cur;
    temp_cur = temp_next;
    /*
        接下來會去判斷他的next是不是null並藉此決定要不要move
    */
    while(temp_next ->next != NULL){
        temp_next = temp_next -> next;
        temp_cur ->next = temp_prev;
        temp_prev = temp_cur;
        temp_cur = temp_next;
    }
    //最後一個round看到他的next是empty後,會讓current往前指並把head pointer 設在最後一個點的位置並回傳
    temp_cur -> next = temp_prev;
    head = temp_cur;
    return head;
}


struct ListNode* reverse(struct ListNode* pre,struct ListNode* cur){
    if(cur == NULL) return pre;
    struct ListNode* temp = cur->next;
    cur->next = pre;
    return reverse(cur,temp); // 呼叫 reverse() 自己本身
}
struct ListNode* reverseList(struct ListNode* head) { // 主程式
    return reverse(NULL, head);
}```
