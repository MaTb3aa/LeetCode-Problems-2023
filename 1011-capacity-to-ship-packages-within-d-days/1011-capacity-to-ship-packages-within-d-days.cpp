class Solution {
public:
    bool ok(int md,vector<int>& weights,int &days){
        int d = 0, sum = 0 ,n = weights.size();
        for(int i=0;i<n;i++){
            if(weights[i]>md)return false;
            if(sum+weights[i]<=md){
                sum+=weights[i];
            }
            else {
                i--;sum=0;d++;
            }
        }
        if(sum)d++;
        return d<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l =0 , r = 1e9,cur=-1,md;
        while(l<=r){
            md=(l+r)>>1;
            if(ok(md,weights,days)){
                cur=md;
                r=md-1;
            }
            else l=md+1;
        }
        return cur;
    }
};