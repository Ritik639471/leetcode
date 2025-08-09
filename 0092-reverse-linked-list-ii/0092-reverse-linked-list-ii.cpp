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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* temp=head,*prev=NULL,*next=head;
        while(temp!=NULL){
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode *ptr1 = head, *ptr2, *ptr3;
        int n=1;
        while (ptr1 != NULL) {
            if (n == right) {
                ptr2=ptr1->next;
                ptr1->next=NULL;
            }
            n++;
            ptr1 = ptr1->next;
        }
        if(left==1){
            head=reverseList(head);
            ptr3=head;
            while(ptr3->next!=NULL){
                ptr3=ptr3->next;
            }
            ptr3->next=ptr2;
            return head;
        }
        n=1;
        ptr1=head;
        while (ptr1 != NULL&&n<left-1) {
            n++;
            ptr1 = ptr1->next;
        }
        ptr1->next=reverseList(ptr1->next);
        ptr3=head;
            while(ptr3->next!=NULL){
                ptr3=ptr3->next;
            }
            ptr3->next=ptr2;
        return head;
    }
};