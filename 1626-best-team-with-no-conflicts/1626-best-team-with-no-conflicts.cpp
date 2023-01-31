class Solution {
public:
    int dp[1003][1003];
    int n;
    int solve(int idx,int lst,vector<pair<int,int>> &v){
        if(idx==n)return 0;
        int &ret = dp[idx][lst] ;
        if(ret!=-1)return ret;
        ret = max(ret,solve(idx+1,lst,v));
        if(v[idx].first >= v[lst].first && v[idx].second >= v[lst].second)
            ret=max(ret,solve(idx+1,idx,v)+v[idx].second);
        return ret;
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        n = scores.size();
        vector<pair<int,int>>v(n);
        for(int i = 0 ; i < n;i++)
            v[i] = {ages[i],scores[i]};
        
       sort(v.begin(),v.end(),[&](pair<int,int>a,pair<int,int>b){
            if(a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });
        
        int ans = 0 ; 
        memset(dp,-1,sizeof dp);        
        for(int i = 0 ; i < n ;i++)
            ans= max(ans,solve(i+1,i,v)+v[i].second);
        
        return ans;
    }
};