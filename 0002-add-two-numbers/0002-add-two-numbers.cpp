class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(-1); // node giả làm đầu danh sách
        ListNode* current = dummyHead; // trỏ đến node hiện tại để thêm node mới
        int carry = 0; // số nhớ khi cộng

        while (l1 != nullptr || l2 != nullptr || carry > 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            int sum = val1 + val2 + carry;
            carry = sum / 10; // tính số nhớ
            int digit = sum % 10; // lấy chữ số hiện tại

            current->next = new ListNode(digit);
            current = current->next;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        return dummyHead->next;
    }
};
