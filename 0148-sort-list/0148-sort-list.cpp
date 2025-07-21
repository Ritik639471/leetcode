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
    ListNode* ml(ListNode* list1,ListNode* list2) {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        ListNode* ptr = list1;
        ListNode* ptr2 = list1,* pt;
        if ((ptr->val) <= (list2->val)) {
            ptr = ptr->next;
        } else {
            pt=list2->next;
            list2->next=list1;
            list1=list2;
            list2=pt;
        }
        ptr = list1;
        ptr2 = list1->next;
        while (ptr2 != NULL && list2 != NULL) {
            if (ptr2->val <= list2->val) {
                ptr = ptr2;
                ptr2 = ptr2->next;
            } else {
                pt=list2->next;
                list2->next=ptr->next;
                ptr->next = list2;
                ptr2 = list2;
                list2 = pt;
                ptr=list2;
            }
        }
        if (list2 != NULL) {
            ptr->next = list2;
        }
        return list1;
    }
    ListNode* help(ListNode* head,int n){
        if(n==0||n==1) return head;
        ListNode* temp=head;
        for(int i=0;i<(n-1)/2;i++){
            temp=temp->next;
        }
        ListNode* t=temp->next;
        temp->next=NULL;
        head=help(head,n/2+n%2);
        t=help(t,n/2);
        return ml(head,t);
    }
    ListNode* sortList(ListNode* head) {
       if(head==NULL||head->next==NULL) return head;
       ListNode* t=head;
       bool f=true;
       int n=0;
       int prev=t->val;
       while(t!=NULL){
          n++;
          if(t->val<prev) f=false;
          prev=t->val;
          t=t->next;
       }
       if(f) return head;
       return help(head,n);
    }
};