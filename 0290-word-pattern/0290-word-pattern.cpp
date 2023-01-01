class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>v;
        stringstream ss(s);
        while(ss>>s)v.push_back(s);
        if(v.size() != pattern.size())return 0;
        unordered_map<string,int>mp2;
        unordered_map<char,int>mp;

        for(int i = 0 ; i < v.size() ; i++){
            if(mp.find(pattern[i])==mp.end())mp[pattern[i]]=i;
            if(mp2.find(v[i])==mp2.end())mp2[v[i]]=i;
            if(mp2[v[i]] != mp[pattern[i]])return 0;
        }
        return 1;
    }
};