/**
 * @param {string} word
 * @return {boolean}
 */
var detectCapitalUse = function(word) {
    var cap=0;
    for(c in word){
        if (word[c]>='A' && word[c]<='Z')cap+=1;
    }
    return (cap==0 || cap == word.length || (cap==1 && word[0]>='A' && word[0]<='Z'))
};