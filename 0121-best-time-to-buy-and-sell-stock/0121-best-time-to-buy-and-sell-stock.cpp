class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=1e9,mx=0;
        for(auto t : prices){
            mx=max(mx,t-mn);
            mn=min(mn,t);
        }
        return mx;
    }
};