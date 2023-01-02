class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt=0;
        for(auto t : word){
            if(isupper(t))cnt++;
        }
        return (cnt==word.size() || !cnt || (cnt==1 && isupper(word[0])));
    }
};