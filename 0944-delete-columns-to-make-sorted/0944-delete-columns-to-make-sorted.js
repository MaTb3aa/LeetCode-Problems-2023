/**
 * @param {string[]} strs
 * @return {number}
 */
var minDeletionSize = function(strs) {
    var cnt = 0 ;
    for(var i = 0 ; i < strs[0].length ; i++){
        for(var j = 1 ; j < strs.length; j++){
            if(strs[j][i] < strs[j-1][i]){cnt+=1;break;}
        }
    }
    return cnt;
};