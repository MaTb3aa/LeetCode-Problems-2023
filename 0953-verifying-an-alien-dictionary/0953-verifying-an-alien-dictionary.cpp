class Solution {
public:
    int ords[26],idx=0;
    bool check(string &a,string &b){
        for(int j= 0 ; j < min(a.size(),b.size()) ; j++){ 
            if(ords[a[j]-'a'] < ords[b[j]-'a'])return 1;
            if(ords[a[j]-'a'] > ords[b[j]-'a'])return 0;
        }
        if(a.size() <= b.size())return 1;
        return 0;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(auto t : order)ords[t-'a']=idx++;
        
        for(int i = 1 ; i < words.size();i++){
            
            if(!check(words[i-1],words[i]))return 0;

        }
        return 1;
        
        
    }
};