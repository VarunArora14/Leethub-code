class Solution {
public:
    void helper(vector<int> curr, int idx, vector<int>& nums, set<vector<int>>& uniqueSubs)
    {
        if(curr.size()>=2) uniqueSubs.insert(curr);
        if(idx==nums.size()) return;
        
        for(int i=idx;i<nums.size();i++)
        {
                // helper(curr, idx+1, nums);
            if(curr.empty() || curr.back()<=nums[i])
            {
                curr.push_back(nums[i]);
                helper(curr, i+1, nums, uniqueSubs);
                curr.pop_back();
            }               
            
        }
        
        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        set<vector<int>> uniqueSubs;
        helper({}, 0, nums, uniqueSubs);
        
        
        vector<vector<int>> ans;
        for(auto u: uniqueSubs)
            ans.push_back(u);
        
        return ans;
    }
};