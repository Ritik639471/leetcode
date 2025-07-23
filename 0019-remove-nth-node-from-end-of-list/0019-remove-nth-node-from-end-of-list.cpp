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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr = head;
        int k = 0;
        while (ptr != NULL) {
            k++;
            ptr = ptr->next;
        }
        ptr = head;
        if (n == k)
            return head->next;
        int i = 1;
        while (ptr->next != NULL && i < k - n) {
            ptr = ptr->next;
            i++;
        }
        ListNode* ptr1 = ptr->next;
        ptr->next = ptr->next->next;
        return head;
    }
};