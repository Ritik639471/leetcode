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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0) return NULL;
        multimap<int,ListNode*> m;
        ListNode* temp;
        int j=0;
        for(int i=0;i<n;i++){
            temp=lists[i];
            while(temp!=NULL){
                m.insert({temp->val,temp});
                temp=temp->next;
                j++;
            }
        }
        if(j==0) return NULL;
        ListNode* head;
        temp=NULL;
        for(auto c: m){
            if(temp!=NULL){
                temp->next=c.second;
                temp=c.second;
            }
            else{
                head=c.second;
                temp=head;
            }
        }
        return head;
    }
};