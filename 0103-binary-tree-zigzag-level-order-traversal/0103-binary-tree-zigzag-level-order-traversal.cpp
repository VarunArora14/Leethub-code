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
        if(root==nullptr) return {};
        queue<TreeNode*> q;
        q.push(root);
        bool reverse_order=false;
        vector<vector<int>> ans;
        
        while(!q.empty())
        {
            int sz=q.size();
            vector<int> level;
            for(int i=0;i<sz;i++)
            {
                auto f = q.front();
                q.pop();
                level.push_back(f->val);
                
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            
            if(reverse_order==true)
            {
                reverse(level.begin(), level.end());
            }
            reverse_order = !reverse_order;
            ans.push_back(level);
        }
        return ans;
    }
};
// modify the level order traversal