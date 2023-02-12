class Solution {
public:
    vector<vector<int>>g;
    long long bfs(int &n,int &seats ,vector<int>dgree){
        vector<int>representatives(n,1);
        queue<int>q;
        for(int i=1;i<n;i++){
            if(dgree[i]==1)
                q.push(i);
        }
        long long foul = 0;
        while(q.size()){
            int node = q.front();q.pop();
            foul+=(representatives[node]+seats-1)/seats;
            for(int child : g[node]){
                representatives[child]+=representatives[node];
                dgree[child]--;
                if(child && dgree[child]==1){
                    q.push(child);
                }
            }
        }
        return foul;
    }  
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size()+1;
        g = vector<vector<int>>(n);
        vector<int>dgree(n);
        for(auto node : roads){
            g[node[0]].push_back(node[1]);
            g[node[1]].push_back(node[0]);
            dgree[node[1]]++;
            dgree[node[0]]++;
        }
        return  bfs(n,seats,dgree);
      
       
    }
};