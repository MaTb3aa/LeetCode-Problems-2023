class Solution {
public:
    int freq[100002];
    vector<int> sortArray(vector<int>& nums) {
        for(auto t : nums)freq[t+50000]++;
        vector<int>v;
        for(int i = 0 ; i <= 100000;i++){
            while(freq[i]--)v.push_back(i-50000);
        }
        return v;
    }
};