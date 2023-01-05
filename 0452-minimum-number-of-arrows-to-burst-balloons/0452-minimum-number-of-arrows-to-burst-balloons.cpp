class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int cnt=0,n=points.size();
        sort(points.begin(),points.end());
        int l = points[0][0] , r=points[0][1];
        for(int i = 1 ; i < n;i++){
            l=max(l,points[i][0]);
            r=min(r,points[i][1]);
            if(l>r){
                cnt++;
                l = points[i][0] , r=points[i][1];
            }
        }
        return cnt+1;
    }
};
