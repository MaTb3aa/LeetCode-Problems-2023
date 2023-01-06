/**
 * @param {number[]} costs
 * @param {number} coins
 * @return {number}
 */
var maxIceCream = function(costs, coins) {
    costs.sort(function (a,b){ return a - b});
    var cnt = 0;
    for (i in costs){
        if(costs[i]<=coins){
            cnt++;
            coins-=costs[i];
        }
    }
    return cnt;
};