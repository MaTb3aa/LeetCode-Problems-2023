class Solution {
public:
    int compress(vector<char>& chars) {
        string s="";
        int cnt=1;
        for(auto t : chars){
            if(s=="" || s.back() != t){
                if(cnt>1)s+=to_string(cnt);
                s+=t;cnt=1;
            }
            else cnt++;
        }
        if(cnt>1)s+=to_string(cnt);
        vector<char> ans;
        for(auto t : s)ans.push_back(t);
        chars = ans;
        return chars.size();
    }
};