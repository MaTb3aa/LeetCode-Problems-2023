/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
var solve = function (p,q){
    if(p === null && q === null)return true;
    if(p === null || q === null)return false;
    
    return (p.val === q.val && solve(p.left, q.left) && solve(p.right, q.right));
 
   
    
}
var isSameTree = function(p, q) {
    return solve(p,q);    
};