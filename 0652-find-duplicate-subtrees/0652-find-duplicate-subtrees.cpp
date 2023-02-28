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
    map<string,int>mp;
    vector<TreeNode*>v;
    
    string solve(TreeNode* root){
        if(!root)return "#" ;
       
        string L = solve(root->left);
        string R = solve(root->right);
        string current = to_string(root->val)+"," + L + "," + R;
        mp[current]++;
        if(mp[current] == 2)v.push_back(root);
        return current;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);        return v;
    }
};