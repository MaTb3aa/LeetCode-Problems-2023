class Union {
    vector<int>par,comp;
    int NumOfCompnent;
public:
    Union(int n){
        NumOfCompnent = n;
        par = vector<int>(n+1);
        iota(par.begin(),par.end(),0);
        comp = vector<int>(n+1,1);
    }
    int find(int u){
        if(u==par[u])return u;
        return par[u] = find(par[u]);
    }
    int join(int u,int v){
        u = find(u); v = find(v);
        if(u==v)return 0;
        if(comp[u] > comp[v]){
            comp[u] += comp[v];
            par[v] = u;
        }
        else {
            comp[v] += comp[u];
            par[u] =v;
        }
        NumOfCompnent--;
        return 1;
    }
    bool isOneComponent (){
        return NumOfCompnent == 1;
    }
};
class Solution {
public:
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        Union alice(n),bob(n);
        int ans = 0;
        for(auto t : edges){
            if(t[0]==3){
                ans += (alice.join(t[1],t[2]) | bob.join(t[1],t[2]));
            }
        }
        for(auto t : edges){
            if(t[0]==1) ans+=alice.join(t[1],t[2]);
            if(t[0]==2) ans+=bob.join(t[1],t[2]);
        }
        if(alice.isOneComponent()  && bob.isOneComponent() )
            return edges.size() - ans;
        return -1;

    }
};