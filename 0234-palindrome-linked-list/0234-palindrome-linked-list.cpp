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
    bool isPalindrome(ListNode* head) {
        ListNode* ptr = head;
        int i = 0;
        while (ptr != NULL) {
            ptr = ptr->next;
            i++;
        }
        int arr[i];
        int n = 0;
        ptr = head;
        while (ptr != NULL) {
            arr[n] = ptr->val;
            ptr = ptr->next;
            n++;
        }
        n = 0;
        while (n < i / 2) {
            if (arr[n] != arr[i - n - 1])
                return 0;
            n++;
        }
        return 1;
    }
};