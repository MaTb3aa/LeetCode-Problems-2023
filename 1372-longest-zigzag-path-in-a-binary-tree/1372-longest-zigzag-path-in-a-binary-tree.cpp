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
    int mx = 0;
    void solve(TreeNode* node, bool canGoLeft, int steps) {
        if (node == nullptr) return;
        
        mx = max(mx, steps);
        
        if (canGoLeft) {
            solve(node->left, false, steps + 1);
            solve(node->right, true, 1);
        } 
        else {
            solve(node->left, false, 1);
            solve(node->right, true, steps + 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        solve(root, false, 0);
        solve(root, true, 0);
        return mx;
    }
};