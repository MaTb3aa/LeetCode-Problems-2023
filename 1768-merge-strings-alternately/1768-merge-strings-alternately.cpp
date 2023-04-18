class Solution {
public:
    string mergeAlternately(string a, string b) {
        string s="";
        int i = 0;
        
        while(i<a.size() && i < b.size())s+=a[i],s+=b[i++];
        while(i<a.size())s+=a[i++];while(i<b.size())s+=b[i++];
        
        return s;

    }
};