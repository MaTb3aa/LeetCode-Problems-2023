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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(root)
        q.push(root);
        while(q.size()){
            int sz = q.size();
            vector<int>v;
            while(sz--){
                auto cur = q.front();q.pop();
                v.push_back(cur->val);
                    if(cur->left)q.push(cur->left);
                    if(cur->right)q.push(cur->right);
            }
            ans.push_back(v);
        }
         for(int i = 1; i < ans.size(); i++){
        if(i &1) 
            reverse(ans[i].begin(), ans[i].end());
      }
        return ans;
    }
};