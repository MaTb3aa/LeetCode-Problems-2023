/**
 * @param {number} n
 * @param {number[][]} trust
 * @return {number}
 */
var findJudge = function(n, trust) {
    let degree = Array(n+1).fill(0);
    for(person of trust){
        degree[(person[0])]--;
        degree[(person[1])]++;
    }
    for(let person =1 ; person<=n;person++){
        if(degree[person] == n-1) return person;
    }
    return -1;
};