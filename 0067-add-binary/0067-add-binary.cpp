class Solution {
public:
    string addBinary(string a, string b) {
       string ans="";
       int carry = 0,i=a.size()-1,j=b.size()-1;
        while(i>=0 || j>=0 || carry>0){
            if(i>=0)carry+=(a[i--]=='1');
            if(j>=0)carry+=(b[j--]=='1');
            ans+=('0'+carry%2);
            carry>>=1;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};