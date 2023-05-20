class Solution {
public:
    
    int n;
    map<string,vector<pair<string,double>>>graph;

    double BFS(string src,string des){

        if(graph.find(src)==graph.end() )return -1;

        set<string>vis;
        queue<pair<string,double>>q;
        q.push({src,1});
        vis.insert(src);
        while(q.size()){
            string cur = q.front().first;
            double cost = q.front().second;
            if(cur==des)return cost;
            q.pop();
            for(auto t : graph[cur]){
                if(vis.find(t.first)==vis.end()){
                    vis.insert(t.first);
                    q.push({t.first,(cost*t.second)});
                }
            }
        }
        return -1;
    }
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)     {
       n = equations.size();
       for(int i=0;i<n;i++){
           graph[equations[i][0]].push_back({equations[i][1],values[i]});
           graph[equations[i][1]].push_back({equations[i][0],1.0/values[i]});
       }
      
        vector<double>ans;
        for(auto t: queries){
            ans.push_back(BFS(t[0],t[1]));
        }
        return ans;
        
    }
};