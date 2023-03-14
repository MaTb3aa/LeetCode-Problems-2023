/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root,int cur){
        if(!root)return 0;
        if(!root->left && !root->right)return cur*10+root->val;
        return solve(root->left,cur*10+root->val)+solve(root->right,cur*10+root->val);
       
        
    }
    int sumNumbers(TreeNode* root) {
       
        return solve(root,0);
    }
};