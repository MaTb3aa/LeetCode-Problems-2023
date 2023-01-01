/**
 * @param {string} pattern
 * @param {string} s
 * @return {boolean}
 */
var wordPattern = function(pattern, s) {
    list = s.split(" ");
    console.log(list);

    var dic1 = {}
    var dic2 = {}
    if(list.length != pattern.length)return false;
    for(var i = 0 ; i < list.length; i++){
        if(list[i] in dic1){}
        else dic1[list[i]]=i;
        if(pattern[i] in dic2){}
        else dic2[pattern[i]]=i;
        if(dic1[list[i]] != dic2[pattern[i]])return false; 
    }
    return true;
};