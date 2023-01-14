class Solution {
public:
  
    vector<vector<int>>g;
    vector<int>vis;
    int idx;
    void dfs(int u){
        for(auto t : g[u]){
            if(!vis[t]){
                vis[t]=idx;
                dfs(t);
            }
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        g = vector<vector<int>>(26);
        vis = vector<int>(26);
        idx = 0;
        for(int i = 0 ; i < s1.size();i++){
            g[s1[i]-'a'].push_back(s2[i]-'a');
            g[s2[i]-'a'].push_back(s1[i]-'a');
        }
       for (int i = 0; i < 26; i++) 
		    if (!vis[i])
                idx++,dfs(i);
            
	   string ans ="";
        for(auto t : baseStr){
            if(!vis[t-'a']){ans+=t;continue;}
             for (int i = 0; i < 26; i++) if(vis[i]==vis[t-'a']){ans+=char('a'+i);break;}
        }
        return ans;
    }
};