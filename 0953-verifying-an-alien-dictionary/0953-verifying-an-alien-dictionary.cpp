class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int ords[26],idx=0;
        for(auto t : order)ords[t-'a']=idx++;
        vector<string>v = words;
        sort(v.begin(),v.end(),[&](string a,string b){
            for(int i= 0 ; i < min(a.size(),b.size()) ; i++){
                if(ords[a[i]-'a'] < ords[b[i]-'a'])return 1;
                else if (ords[a[i]-'a'] > ords[b[i]-'a'])return 0;
            }
            if(a.size() < b.size())return 1;
            return 0;
        });
        return v == words;
    }
};