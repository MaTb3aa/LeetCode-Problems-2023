class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        for(auto t : s){
            if(t=='(' || t=='{' ||t=='[')stk.push(t);
            else {
                if(stk.empty())return false;
                if(stk.top() == '(' && t==')')stk.pop();
                else if(stk.top() == '[' && t==']')stk.pop();
                else if(stk.top() == '{' && t=='}')stk.pop();
                else break;
            }
        }
        return stk.empty();
    }
};