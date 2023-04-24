class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pr;
        for(auto t : stones)pr.push(t);
        
        while(pr.size()>1){
            int x = pr.top();pr.pop();
            int y = pr.top();pr.pop();
            if(x!=y)pr.push(x-y);
        }
        return pr.size() ? pr.top() : 0;
    }
};