class Solution {
public:
    int rob(vector<int>& nums) {
        // for cases 1 and 2, return dp[0] and max dp[0], dp[1]
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n,0);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]); // decides which house to rob
        for(int i=2;i<n;i++)
        {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        // for(int i: dp)
        //     cout<<i<<" ";
        return dp[n-1];
    }
};