class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
         vector<int>v(n);
        v[0] = pref[0];
        int lst = pref[0];
        for(int i =1;i<n;i++){
            v[i] = lst^pref[i];
            lst ^=v[i];
        }
        return v;
    }
};