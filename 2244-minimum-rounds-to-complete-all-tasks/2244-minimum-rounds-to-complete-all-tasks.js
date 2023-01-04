/**
 * @param {number[]} tasks
 * @return {number}
 */
var minimumRounds = function(tasks) {
    var mp={}
    for(i in tasks){
        if(tasks[i] in mp)mp[tasks[i]]+=1;
        else mp[tasks[i]]=1;
    }
    var ans = 0;
    for(t in mp){
        if(mp[t]==1)return -1;
        ans+=Math.ceil((mp[t])/3);
    }
    return ans;
};