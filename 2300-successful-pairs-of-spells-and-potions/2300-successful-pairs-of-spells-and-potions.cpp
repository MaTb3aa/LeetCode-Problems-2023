class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>ans;
        int n = potions.size();
        for(auto t : spells){
            int st = 0 , ed = n-1,cur = n , md;
            while(st<=ed){
                md=(st+ed)>>1;
                if(1LL * potions[md]* t >=success){
                    ed=md-1;
                    cur = md;
                }
                else st=md+1;
            }
            ans.push_back(n-cur);
        }
        return ans;
    }
};