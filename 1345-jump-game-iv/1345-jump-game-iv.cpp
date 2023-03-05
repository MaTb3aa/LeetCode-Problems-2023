class Solution {
public:
    
    int minJumps(vector<int>& v) {
        int n= v.size();
        unordered_map<int,vector<int>>mp;
        for(int i = 0 ; i < n;i++)mp[v[i]].push_back(i);
        
        queue<int>q;
        vector<int>vis(n);
        q.push(0);
        int ans = 0 ; 
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int cur = q.front();q.pop();
                if(cur==n-1)return ans;

                if(cur+1 < n && !vis[cur+1]){
                    vis[cur+1]=1;
                    q.push(cur+1);
                }
                if(cur-1 >= 0 && !vis[cur-1]){
                    vis[cur-1]=1;
                    q.push(cur-1);
                }
                for(auto idx : mp[v[cur]]){
                    if(!vis[idx]){
                        vis[idx]=1;
                        q.push(idx);
                    }
                }
                mp.erase(v[cur]);
            }
            ans++;
            
        }
        return ans;
    
    }
};