class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = 0 ;
        vector<int>v;
        while(num.size() || k > 0 || carry){
            carry +=k%10;k/=10;
            if(num.size())carry+=num.back(),num.pop_back();
            v.push_back(carry%10);carry/=10;
        }
        
        reverse(v.begin(),v.end());
        return v;
    }
};