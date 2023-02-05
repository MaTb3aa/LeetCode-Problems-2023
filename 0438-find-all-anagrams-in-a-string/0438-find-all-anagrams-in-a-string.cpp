class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>a(26),b(26);
        for(auto t : p)a[t-'a']++;
        int n = p.size();
        vector<int>ans;

        if(n > s.size())return ans;
        for(int i = 0 ; i <n;i++)b[s[i] - 'a']++;
        if(a==b)ans.push_back(0);
        for(int i = n ; i < s.size() ;++i){
            b[s[i-n]-'a']--;
            b[s[i]-'a']++;
            if(a==b)ans.push_back(i-n+1);
        }
        return ans;
    }
};