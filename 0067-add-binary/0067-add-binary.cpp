class Solution {
public:
    string addBinary(string a, string b) {
       string ans="";
       int sum = 0;
        while(a.size() && b.size()){
            if(a.back()=='1')sum++;
            if(b.back()=='1')sum++;
            if(!sum)ans+='0';
            else if(sum==1)ans+="1",sum=0;
            else if(sum==2)ans+="0",sum=1;
            else ans+="1",sum=1;
            a.pop_back();
            b.pop_back();
        }
        while(a.size()){
            if(a.back()=='1')sum++;
            if(!sum)ans+="0";
            else if(sum==1)ans+="1",sum=0;
            else if(sum==2)ans+="0",sum=1;
            a.pop_back();
        }
        while(b.size()){
            if(b.back()=='1')sum++;
            if(!sum)ans+="0";
            else if(sum==1)ans+="1",sum=0;
            else if(sum==2)ans+="0",sum=1;
            b.pop_back();
        }
        if(sum)ans+="1";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};