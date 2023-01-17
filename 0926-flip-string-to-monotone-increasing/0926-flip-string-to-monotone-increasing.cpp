class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int zeros= 0,ones=0,ans=1e9;
        
        for(int i=0;i<s.size();i++)zeros+=(s[i]=='0');
    
        
        for(int i=0;i<s.size();i++){
            ans=min(ans,ones+zeros);
            ones+=(s[i]=='1');
            zeros-=(s[i]=='0'); 
        }
        return min(ans,ones+zeros);
    }
};