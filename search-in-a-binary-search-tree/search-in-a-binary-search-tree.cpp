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
    TreeNode* ans = nullptr;

    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)return ans;
        if(root->val==val){ans = root;}
        searchBST(root->left,val);
        searchBST(root->right,val);
        return ans;
    }
};