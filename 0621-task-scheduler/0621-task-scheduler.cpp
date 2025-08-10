class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int s=tasks.size();
        vector<int>a(26,0);
        for(int i=0;i<s;i++) a[tasks[i]-'A']++;
        sort(a.begin(),a.end());
        int b=1;
        for(int i=24;i>=0;i--){
            if(a[i]==a[25]) b++;
        }
        return max((a[25]-1)*(n+1)+b,s);
    }
};