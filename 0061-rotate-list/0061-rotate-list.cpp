/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* ptr = head;
        int n = 0;
        while (ptr != NULL) {
            ptr = ptr->next;
            n++;
        }
        k = k % n;
        ptr = head;
        int i = 0;
        ListNode* ptr1 = head;
        if (k == 0)
            return head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
            ++i;
            if (i == n - k - 1)
                ptr1 = ptr;
        }
        ptr->next = head;
        head = ptr1->next;
        ptr1->next = NULL;
        return head;
    }
};