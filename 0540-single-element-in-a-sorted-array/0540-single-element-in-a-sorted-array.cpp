class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int x=0;
        for(auto t :nums)x^=t;
        return x;
    }
};