class Solution {
public:
    vector<string>curS;
    vector<vector<string>>ans;
    int n;
    bool isBalindrom(int l,int r,string &s){
        while(l<r)if(s[l++]!=s[r--])return false;
        return true;
    }
    void solve(int idx,string &s){
        if(idx>=n)ans.push_back(curS);
        for(int end = idx;end<n;end++){
            if(isBalindrom(idx,end,s)){
                curS.push_back(s.substr(idx,end-idx+1));
                solve(end+1,s);
                curS.pop_back();
            }
                
        }
    }
    
   
    
    vector<vector<string>> partition(string s) {
        n = s.size();
        solve(0,s);
        return ans;
    }
};