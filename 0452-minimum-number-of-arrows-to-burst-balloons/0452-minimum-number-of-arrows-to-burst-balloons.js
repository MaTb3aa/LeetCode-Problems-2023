/**
 * @param {number[][]} points
 * @return {number}
 */
var findMinArrowShots = function(points) {
   points.sort(function(a,b) {
        return a[0]-b[0]
    });
    var ans = 0,l=points[0][0],r=points[0][1];
    for(let i = 1 ; i < points.length;i++){
        l=Math.max(l,points[i][0]);
        r=Math.min(r,points[i][1]);
        if(l>r){
            l=points[i][0],r=points[i][1];
            ans+=1;
        }
    }
    return ans+1;
};