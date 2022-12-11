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
    int maxSum;
    int helper(TreeNode* roo)
    {
        if(roo==nullptr) return 0;
        int left = helper(roo->left);
        int right = helper(roo->right);
        
        int maxLR = max(left, right); // find max of left and right paths and later add root->val to it
        
        int max2 = max(roo->val, roo->val+maxLR); // max of root and prev max plus + root->val
        int maxAll = max(max2, left+right+roo->val); // max(till now, complete path)
        
        maxSum = max(maxSum, maxAll);
        
        // dont return maxAll as it will consider complete path as well which is child node + left + right
        // that is not possible as child can either go left or right
        return max2;
    }
    
    int maxPathSum(TreeNode* root) {
        maxSum=INT_MIN;
        helper(root);
        
        return maxSum;
    }
};

// For max value we have 4 options, rootval, leftPath, rightPath and completePath

// for returning the left and right paths we return max({root->val, leftPath, rightPath}) where leftPath includes the 
// root->val so we can probably ignore first variable

// For the 4 options, we have to understand one thing, we can EITHER go LEFT OR RIGHT NOT BOTH.
// Because, for current node's parent node, if we were to include node.val + node.left +node.right in the maxPathSum, it 
// would VIOLATE the PRINCIPLE that we can only traverse each node ONCE!!! Since its IMPOSSIBLE to traverse from node-
// >left->right->node's parent without re-visiting node itself, we cannot include node.val + node.left + node.right in the 
// return value!