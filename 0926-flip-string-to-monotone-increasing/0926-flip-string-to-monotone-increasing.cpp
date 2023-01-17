class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int zeros= 0,ones=0,ans=1e9;
        
        for(char &t : s)zeros+=(t=='0');
        
        for(char &t : s){
            ans=min(ans,ones+zeros);
            ones+=(t=='1');
            zeros-=(t=='0'); 
        }
        return min(ans,ones+zeros);
    }
};