class SummaryRanges {
public:
    set<vector<int>>st;
    int vis[100003];
    SummaryRanges() {
        memset(vis,0,sizeof vis);
    }
    
    void addNum(int value) {
        value++;
        if(vis[value])return ;
        vis[value]=1;
        if(vis[value-1] && vis[value+1]){
            auto it1 = st.upper_bound({value,0});
            if(it1!=st.begin())--it1;
            auto it2 = st.lower_bound({value,0});
            if(it2==st.end())it2--;
            st.insert({(*it1)[0],(*it2)[1]});
            st.erase(it1); st.erase(it2);

        }
        else if(vis[value+1]){
            auto it = st.upper_bound({value,0});
            if(it==st.end())--it;
             st.insert({value,(*it)[1]});
             st.erase(it);
            
        }
        else if(vis[value-1]){
            vector<int>tmp;
            auto it = st.upper_bound({value,0});
            if(it!=st.begin())--it;
             st.insert({(*it)[0],value});
             st.erase(it);

            
        }
        else st.insert({value,value});
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>v;
        for(auto t : st)v.push_back({t[0]-1,t[1]-1});
        return v;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */