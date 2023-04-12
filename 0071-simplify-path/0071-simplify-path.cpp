class Solution {
public:
    string simplifyPath(string path) {
        vector<string>stk;
        string cur="";
        path+='/';
        for(auto t  : path){
            if(t=='/'){
                if(cur.size()){
                    if(cur==".."){
                        if(stk.size())stk.pop_back();
                    }
                    else if(cur=="."){}
                    else 
                        stk.push_back(cur);
                }
                cur="";
            }
            else cur+=t;
        }
        string ans="";
        for(auto t : stk){
            ans+="/";
            ans+=t;
        }
        if(ans=="")ans+="/";

        return ans;
    }
};