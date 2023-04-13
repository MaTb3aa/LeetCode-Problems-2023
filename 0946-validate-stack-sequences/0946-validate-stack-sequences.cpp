class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>stk;
        int i = 0;
        for(auto t : pushed){
            stk.push(t);
            while(i<popped.size() && stk.size() && stk.top() == popped[i]){
                i++;stk.pop();
            }
        }
       // cout<<stk.size() <<" "<<i<<endl;
        return stk.empty() && i == popped.size();
    }
};