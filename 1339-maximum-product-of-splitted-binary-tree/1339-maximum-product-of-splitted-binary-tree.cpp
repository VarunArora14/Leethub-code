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
    long long ans=0, total=0;
    int helper(TreeNode* roo)
    {
        if(roo==nullptr) return 0;
        int curr = helper(roo->left) + helper(roo->right) + roo->val;
        ans = max(ans, (total-curr)*curr);
        return curr; // sum of BT
    }
    int maxProduct(TreeNode* root) {
        
        total = helper(root); // find sum of BT
        helper(root); // dfs again to get the max ans
        return ans% int(1e9+7);
    }
};

// first find the sum of subtree and then for each edge find result as res = (total-curr)*curr where curr is sum till now
// of traversal and total is sum of tree. By this we check for each edge the max and return the ans