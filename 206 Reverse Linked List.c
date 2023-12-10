#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head){
    /*�ڭ̤@�}�l�Ƕi�ӭn���P�_list�O���O�ťH�ξ��linklist�O���O�u���@���I,
    �p�G�O�Ū��ܧڭ̴N�^��NULL�p�G�O�H���I���ܧڭ̴N�����^��head pointer
    */
    if(head == NULL){
        return NULL;
    }
    if(head -> next == NULL){
        return head;
    }
    /*
        ���U�ӧڷ|�ŧi�T��list node pointer,���O�O���x�s�e���᪺�T�Ӧ�m��pointer
    */
    
    struct ListNode *temp_prev = head;
    struct ListNode *temp_next = head;
    struct ListNode *temp_cur = head;
    //���۷|��next pointer�����e��
    temp_next = temp_next -> next;
    /* 
        *testing above said there will at least one node in this list
        *and the below is special case to solve first two node in list
    */
    /*
        ���e������ݥL��next�O���Onull�p�G���O���ܴN�b��next���e����ĤT���I,���p�G�Onull�N��ܾ��linklist�u������I
        �ҥH�N��Ĥ@���I��next����null,�ç�ĤG���I��next�u��e��,�æ^�ǲĤG���I��pointer 
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
        ���۴N�O�T���I�H�W�����p,
        �ڭ̭n����ĤG���I(�̫�^�Ǫ�headpointer���V�L),
        �åB��Ĥ@���I���VNULL,
        �A�ӴN�O��previous current �H��next �����L�̪�next����
    */
    temp_cur = temp_cur -> next;
    temp_prev -> next = NULL;
    temp_cur -> next = temp_prev;
    temp_prev = temp_cur;
    temp_cur = temp_next;
    /*
        ���U�ӷ|�h�P�_�L��next�O���Onull���Ǧ��M�w�n���nmove
    */
    while(temp_next ->next != NULL){
        temp_next = temp_next -> next;
        temp_cur ->next = temp_prev;
        temp_prev = temp_cur;
        temp_cur = temp_next;
    }
    //�̫�@��round�ݨ�L��next�Oempty��,�|��current���e���ç�head pointer �]�b�̫�@���I����m�æ^��
    temp_cur -> next = temp_prev;
    head = temp_cur;
    return head;
}


struct ListNode* reverse(struct ListNode* pre,struct ListNode* cur){
    if(cur == NULL) return pre;
    struct ListNode* temp = cur->next;
    cur->next = pre;
    return reverse(cur,temp); // �I�s reverse() �ۤv����
}
struct ListNode* reverseList(struct ListNode* head) { // �D�{��
    return reverse(NULL, head);
}```
