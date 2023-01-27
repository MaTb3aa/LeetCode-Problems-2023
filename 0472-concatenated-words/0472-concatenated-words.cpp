class Solution {
public:
    bool dfs(int idx,unordered_map<string,int>&mp,string &s){
        if(idx==s.size())return true;
        string tmp="";
        for(int i=idx;i<s.size();i++){
            tmp+=s[i];
            if(mp[tmp]>0 && dfs(i+1,mp,s))return true;
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string,int>mp;
        for(auto t : words)mp[t]++;
        vector<string>ans;
        for(auto word : words){
            mp[word]--;
            if(dfs(0,mp,word))
                ans.push_back(word);
            mp[word]++;
        }
        return ans;
    }
};