class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int idx=0,miss=0;
        for(int i=1;i<=arr.size()+k;i++){
            if(idx<arr.size() && arr[idx]==i)idx++;
            else miss++;
            if(miss==k)return i;
        }
        return -1;
    }
};