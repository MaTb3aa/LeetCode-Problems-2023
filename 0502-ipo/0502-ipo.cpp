class Solution {
public:
    
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        set<pair<int,int>>stProfit,stCapital;
        priority_queue<pair<int,int>>pr;
        for(int i = 0 ; i < profits.size();i++){
            if(capital[i]<=w){
                pr.push({profits[i],i});
            }
            else{
                stCapital.insert({capital[i],i});
            }
        }

        while(k-- && pr.size()){
            w+=pr.top().first;pr.pop();
            while(stCapital.size() ){
                auto it = stCapital.begin();
                if((*it).first > w)break;
                pr.push({profits[(*it).second],(*it).second});
                stCapital.erase(stCapital.begin());
            }           
        }
        return w;
    }
};