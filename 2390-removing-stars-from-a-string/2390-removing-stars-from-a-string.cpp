class Solution {
public:
    string removeStars(string s) {
        string d="";
        for(auto t : s){
            if(t=='*'){
                if(d.size())d.pop_back();
            }
            else d+=t;
        }
        return d;
    }
};