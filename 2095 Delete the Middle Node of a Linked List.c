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
        ���إߨ���ܼƤ@�Ӭ�int�@�Ӭ�float�ӭp��X���linklist��node�`��
        �M��N�䰣�H�G�����target���x�s
        �åBallocate���memory space��pointer
    */
    struct ListNode *temp = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode *targetNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    //�o���traverse�㰱linklist��count���linklist��node��
    temp ->next = head;
    while(temp -> next != NULL){
        count++;
        temp = temp ->next;
    }
    /*
    �o��⧹����|��targetnode��next�ӫ��Vhead,�åѦ��ǳƧ�X�n�R�����ؼ��I
    ��X�����I��,�|���@�ӱq�Y�������pointer�L�|�b�U�@���I�p�G�Otarget node �ndelete����
    �N�|������L��next����targetnode��next �Ǧ���bypass�L
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