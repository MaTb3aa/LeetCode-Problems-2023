class Solution {
public:
    bool checkInclusion(string s1, string s2) {
         vector<int>freq(26,0),freq2(26,0);
        for(auto t : s1)freq[t-'a']++;
        int n = s1.size() , n2 = s2.size();
        if(n>n2)return false;
        for(int i = 0 ; i < n ;i++)freq2[s2[i]-'a']++;
        if(freq==freq2)return true;
        for(int i = n ; i < n2 ;i++){
            freq2[s2[i]-'a']++;
            freq2[s2[i-n]-'a']--;
            if(freq==freq2)return true;
        }
        return false;
    }
};