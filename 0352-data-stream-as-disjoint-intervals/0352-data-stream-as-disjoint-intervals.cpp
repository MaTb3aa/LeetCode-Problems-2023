class SummaryRanges {
public:
    set<vector<int>>st;
    int vis[100003];
    SummaryRanges() {
        memset(vis,0,sizeof vis);
        st.clear();
    }
    
    void addNum(int value) {
        value++;

        if(vis[value])return ;
        if(vis[value-1] && vis[value+1]){
           // cout<<value-1-1<<" "<<value-1<<" "<<value+1-1<<endl;
            auto it1 = st.upper_bound({value,0});
            if(it1!=st.begin())--it1;
            
            auto it2 = st.lower_bound({value,0});
           if(it2==st.end())it2--;
            
           // cout<<(*it1)[0]<<" "<<(*it1)[1]<<" && "<<(*it2)[0]<<" "<<(*it2)[0]<<endl;
            vector<int>tmp = {(*it1)[0],(*it2)[1]};
            st.erase(it1); st.erase(it2);
            st.insert(tmp);

        }
        else if(vis[value+1]){
            auto it = st.upper_bound({value,0});
            if(it==st.end())--it;
            //cout<<value-1<<endl;
            //cout<<(*it)[0]<<" "<<(*it)[1]<<endl;

             vector<int>tmp = {value,(*it)[1]};
             st.erase(it);
             st.insert(tmp);
            
        }
        else if(vis[value-1]){
            vector<int>tmp;
            auto it = st.upper_bound({value,0});
            if(it!=st.begin())--it;

             tmp = {(*it)[0],value};
             st.erase(it);
             st.insert(tmp);
            
        }
        else {
           vector<int>tmp = {value,value};
            st.insert(tmp);
        }
        vis[value]=1;
       
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