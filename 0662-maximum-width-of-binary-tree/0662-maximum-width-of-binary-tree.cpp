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
class Solution 
{
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
       if(root==NULL)
       return 0;
       int mx_width=1;
       queue<pair<TreeNode*, int>>q;
       q.push({root, 0});
       while(!q.empty())
       {
           int sz=q.size();   
           int st=q.front().second;
           int end=q.back().second;
           mx_width=max(mx_width, (end-st+1));
           for(int i=0; i<sz; i++)
           {
               TreeNode* cur_node=q.front().first;
               int cur_idx=q.front().second;
               q.pop();
               if(cur_node->left!=NULL)
               q.push({cur_node->left, cur_idx*1LL*2+1});
               if(cur_node->right!=NULL)
               q.push({cur_node->right, cur_idx*1LL*2+2});
           }
       }
       return mx_width;
    }
};