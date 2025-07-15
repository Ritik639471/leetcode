class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        unordered_map<string,bool>mp;
        for(auto c: wordList){
            mp[c]=true;
        }
        queue<pair<string,int>>rq;
        rq.push({beginWord,1});
        while(!rq.empty()){
            auto c=rq.front();
            rq.pop();
            for(int i=0;i<c.first.length();i++){
                for(char j='a';j<='z';j++){
                    string s=c.first;
                    s[i]=j;
                    if(mp[s]&&s==endWord) return c.second+1;
                    if(mp[s]){
                        rq.push({s,c.second+1});
                        mp[s]=false;
                    }
                }
            }
        }
        return 0;
    }
};