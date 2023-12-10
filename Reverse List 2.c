?：那有沒有可能left跟right的值會不在linklist裡面呢,還有有沒有可能left會等於right的值

?：那我沒有問題了coding


struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (!head || !head->next) {
        return head;  // 如果鏈表為空或只有一個節點，不需要反轉，直接返回
    }

    struct ListNode* dummy = malloc(sizeof(struct ListNode));  // 創建一個虛擬節點，使代碼更簡潔
    dummy->next = head;

    struct ListNode* prev = dummy;

    // 移動 prev 到 left - 1 位置
    for (int i = 0; i < left - 1; i++) {
        prev = prev->next;
    }

    struct ListNode* current = prev->next;

    // 反轉範圍內的節點
    for (int i = 0; i < right - left; i++) {
        struct ListNode* next_node = current->next;  // 下一個節點
        current->next = next_node->next;  // 刪除 next_node
        next_node->next = prev->next;  // 插入 next_node 到 prev 的後面
        prev->next = next_node;
    }

    struct ListNode* new_head = dummy->next;  // 新的鏈表頭
    free(dummy);  // 釋放虛擬節點

    return new_head;
}
