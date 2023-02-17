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
    void helper(TreeNode* root, vector<int>& res)
    {
        if(root==nullptr) return;
        
        helper(root->left,res);
        res.push_back(root->val); // inorder
        helper(root->right, res);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> nums;
        helper(root, nums);
        int ans=INT_MAX;
        
        for(int i=0;i<nums.size()-1;i++)
        {
            ans = min(ans, nums[i+1]-nums[i]);
        }
        return ans;
    }
};

// since it is as bst , min diff betw parent and child nodes only