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
    ListNode* partition(ListNode* head, int x) {
        ListNode *ptr1 = head, *prev1=NULL;
        ListNode *ptr2 = head, *prev2=NULL;
        if (head == NULL || head->next == NULL)
            return head;
        while (ptr2!=NULL&&ptr2->val <x) {
            prev2 = ptr2;
            ptr2 = ptr2->next;
        }
        ptr1=ptr2;
        while (ptr1!=NULL&&ptr1->val >= x) {
            prev1 = ptr1;
            ptr1 = ptr1->next;
        }
        if(ptr2==NULL) return head;
        while (ptr1 != NULL) {
            if (ptr1->val < x) {
                ListNode* temp = ptr1;
                if(prev1!=NULL) prev1->next = ptr1->next;
                else prev1=temp;
                ptr1 = ptr1->next;
                if (ptr2 == head) {
                    temp->next = head;
                    prev2=temp;
                    head = temp;
                } else {
                    temp->next = ptr2;
                    prev2->next = temp;
                    prev2 = temp;
                }
            } else {
                prev1 = ptr1;
                ptr1 = ptr1->next;
            }
        }
        return head;
    }
};