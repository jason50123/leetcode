?�G�����S���i��left��right���ȷ|���blinklist�̭��O,�٦����S���i��left�|����right����

?�G���ڨS�����D�Fcoding


struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (!head || !head->next) {
        return head;  // �p�G����ũΥu���@�Ӹ`�I�A���ݭn����A������^
    }

    struct ListNode* dummy = malloc(sizeof(struct ListNode));  // �Ыؤ@�ӵ����`�I�A�ϥN�X��²��
    dummy->next = head;

    struct ListNode* prev = dummy;

    // ���� prev �� left - 1 ��m
    for (int i = 0; i < left - 1; i++) {
        prev = prev->next;
    }

    struct ListNode* current = prev->next;

    // ����d�򤺪��`�I
    for (int i = 0; i < right - left; i++) {
        struct ListNode* next_node = current->next;  // �U�@�Ӹ`�I
        current->next = next_node->next;  // �R�� next_node
        next_node->next = prev->next;  // ���J next_node �� prev ���᭱
        prev->next = next_node;
    }

    struct ListNode* new_head = dummy->next;  // �s������Y
    free(dummy);  // ��������`�I

    return new_head;
}
