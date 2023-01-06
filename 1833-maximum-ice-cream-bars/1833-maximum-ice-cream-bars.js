/**
 * @param {number[]} costs
 * @param {number} coins
 * @return {number}
 */
var maxIceCream = function(costs, coins) {
    let n = costs.length;
    const mx = Math.max(...costs);
    let cnt = 0 ;
    let freq = Array(mx+1).fill(0);
    
    for(let x of costs)freq[x]+=1;
    
    for(let i = 1; i<= mx  ;i++){
        let tmp = Math.min(Math.floor(coins/i),freq[i]);
        cnt+=tmp;
        coins-=tmp*i;
    }
    return cnt;
};