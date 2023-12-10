#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteMiddle(struct ListNode* head){
    float count = 0;
    int target= 0;
    /*
        先建立兩個變數一個為int一個為float來計算出整條linklist的node總數
        然後將其除以二之後用target來儲存
        並且allocate兩個memory space給pointer
    */
    struct ListNode *temp = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode *targetNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    //這邊先traverse整停linklist並count整條linklist的node數
    temp ->next = head;
    while(temp -> next != NULL){
        count++;
        temp = temp ->next;
    }
    /*
    這邊算完之後會把targetnode的next來指向head,並由此準備找出要刪除的目標點
    找出中間點後,會有一個從頭走到尾的pointer他會在下一個點如果是target node 要delete的話
    就會直接把他的next指到targetnode的next 藉此來bypass他
    */
    targetNode -> next = head;
    if(count == 1){
        return NULL;
    }else{
        target = floor(count/2);//To calculate the middle number of linklist
        for(int i = 0; i < target; i++){
            targetNode = targetNode -> next;
        }
        targetNode ->next = (targetNode ->next) -> next;
    
    }
    return head;
}