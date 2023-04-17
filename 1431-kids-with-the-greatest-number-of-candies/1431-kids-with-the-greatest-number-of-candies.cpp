class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans;
        int mx = *max_element(candies.begin(),candies.end());
        for(auto t : candies){
            ans.emplace_back((t+extraCandies)>=mx);
        }
        return ans;
    }
};