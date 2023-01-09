/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var list;
var dfs = function (root){
    if(root==null)return ;
    list.push(root.val);
    dfs(root.left);
    dfs(root.right);
}
var preorderTraversal = function(root) {
    list = Array();
    dfs(root);
    return list;
};