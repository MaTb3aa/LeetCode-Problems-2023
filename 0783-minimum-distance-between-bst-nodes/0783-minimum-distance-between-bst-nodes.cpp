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
    vector<int>v;
    void solve(TreeNode* root){
        if(!root)return ;
        v.push_back(root->val);
        solve(root->left);
        solve(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        solve(root);
        sort(v.begin(),v.end());
        int ans = 1e9;
        for(int i=1;i<v.size();i++)ans=min(ans,v[i]-v[i-1]);
        return ans;
    }
};