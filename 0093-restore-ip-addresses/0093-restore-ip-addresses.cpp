class Solution {
public:
    vector<string>ans;
    string s="";
    int n;
    // valid
    bool valid(string ip){
        int cnt = 0,cur=0;
        string tmp = "";
        for(auto t : ip){
            if(cur>255 )return 0;
            if(t=='.'){
                cnt++;
                if(to_string(cur)!=tmp)return 0;
                cur=0; tmp ="";
            }
            else {
                tmp+=t;
                cur= cur * 10+(t-'0');
            }
        }
        if(to_string(cur)!=tmp || cur > 255)return 0;
        return cnt==3 && ip.back()!='.';
    }
    
    void solve(int i,string ip,int len,string &s){
          
        
        if(i==n){
            if(valid(ip))ans.push_back(ip);
            return ;
        }
            // do it alone
            ip.push_back(s[i]);
            solve(i+1,ip,len+1,s);
            ip.pop_back();
            
            // do it with add .
            ip.push_back(s[i]);
            ip.push_back('.');
            solve(i+1,ip,0,s);
            ip.pop_back();
            ip.pop_back();
        
    }
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        solve(0,"",0,s);
        return ans;
    }
};