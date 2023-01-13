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
    int dfs(TreeNode* roo, int& ans)
    {
        if(roo==nullptr) return 0;
        int l = dfs(roo->left, ans);
        int r = dfs(roo->right, ans);
        
        ans = max(l+r, ans); // store ans for children as subtrees can have better ans, dont do +1, consider 1st example
        return max(l,r)+1; // longest child length with current node considered
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
         dfs(root,ans);
        return ans;
    }
};