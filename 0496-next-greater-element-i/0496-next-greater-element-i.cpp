class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int mx=0;
        for(int i=0;i<n2;i++){
            mx=max(mx,nums2[i]);
        }
        vector<int>a(mx+1);
        for(int i=0;i<n2;i++) a[nums2[i]]=i;
        int b;
        stack<int>st;
        for(int i=n2-1;i>=0;i--) {
            while(!st.empty()&&st.top()<nums2[i]){
                st.pop();
            }
            if(st.empty()){
                st.push(nums2[i]);
                nums2[i]=-1;
            }else{
                b=st.top();
                st.push(nums2[i]);
                nums2[i]=b;
            }
        }
        for(int i=0;i<n1;i++){
            nums1[i]=nums2[a[nums1[i]]];
        }
        return nums1;
    }
};