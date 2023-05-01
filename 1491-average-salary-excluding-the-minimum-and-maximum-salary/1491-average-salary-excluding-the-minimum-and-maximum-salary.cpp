class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        salary.pop_back();
        salary.erase(salary.begin(),salary.begin()+1);
        long long sum = accumulate(salary.begin(),salary.end(),0);
        return (double)sum / salary.size();
    }
};