class Solution {
public:
    void help(vector<int>& nums,int i,int j,int& a){
        if(i==j) return;
        int d=(i+j)/2;
        help(nums,i,d,a);
        help(nums,d+1,j,a);
        vector<int>b(j-i+1);
        int k=i,l=d+1;
        while(k<=d&&l<=j){
            if(2*1LL*nums[l]<nums[k]){
                a+=d-k+1;
                l++;
            }else k++;
        }
        k=i;
        l=d+1;
        int m=0;
        while(k<=d&&l<=j){
            if(nums[k]<=nums[l]){
                b[m++]=nums[k++];
            }else{
                b[m++]=nums[l++];
            }
        }
        while(k<=d){
            b[m++]=nums[k++];
        }
        while(l<=j){
            b[m++]=nums[l++];
        }
        for(m=0;m<j-i+1;m++){
            nums[i+m]=b[m];
        }
    }
    int reversePairs(vector<int>& nums) {
        int a=0;
        int n=nums.size();
        help(nums,0,n-1,a);
        return a;
    }
};