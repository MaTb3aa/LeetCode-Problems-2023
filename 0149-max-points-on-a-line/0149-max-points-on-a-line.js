/**
 * @param {number[][]} points
 * @return {number}
 */
var gcd = function(a, b) {
  if (!b) return a;
  return gcd(b, a % b);
}
var maxPoints = function(v) {
    let n = v.length;
    let ans = 1;
    for(let i = 0 ; i < n ; i++){
        let vertical =1 , overlap =1 , curMax=0;
        let mp ={};
        for(let j = i+1; j < n ; j++){
            if(v[i]==v[j])overlap+=1;
            else if(v[i][0]==v[j][0])vertical+=1;
            else {
                let xDif = v[j][0] - v[i][0];
                let yDif = v[j][1] - v[i][1];
                let g = gcd(xDif,yDif);
                xDif/=g;
                yDif/=g;
                if([xDif,yDif] in mp)mp[[xDif,yDif]]+=1;
                else mp[[xDif,yDif]]=1;
                curMax=Math.max(curMax,mp[[xDif,yDif]]);
            }
        }
         ans = Math.max(vertical,Math.max(ans,overlap+curMax));
    }
    return ans;
    
};