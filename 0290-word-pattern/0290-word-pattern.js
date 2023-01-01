/**
 * @param {string} pattern
 * @param {string} s
 * @return {boolean}
 */
var wordPattern = function(pattern, s) {
    s = s.split(" ");
    if(s.length != pattern.length || new Set(s).size != new Set(pattern.split("")).size)return false;
    const dic = {};
    for(let i = 0 ; i < pattern.length ; i++){
        if(dic[pattern[i]]){
            if(dic[pattern[i]] !== s [i])return false;
        }
        else dic[pattern[i]] = s[i];
    }
    return true;
};