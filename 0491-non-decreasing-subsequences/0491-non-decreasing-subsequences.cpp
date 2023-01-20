class Solution {
public:
    int n;
    set<vector<int>>ans;
    
    void solve(int idx,vector<int>& v,vector<int>& nums){
        if(idx==n){
            if(v.size()>1)ans.insert(v);
            return;
        }
        if(nums[idx]>=v.back()){
            v.push_back(nums[idx]);
            solve(idx+1,v,nums);
            v.pop_back();
        }
         
            solve(idx+1,v,nums);

        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n=nums.size();
        vector<int>v;
        for(int i=0;i<n;i++){
            v.push_back(nums[i]);
            solve(i+1,v,nums);
            v.pop_back();
        }
        vector<vector<int>>vv;
        for(auto t : ans)vv.push_back(t);
        return vv;
       
    }
};