class Solution {
public:
    int solve(vector<int>& v1, vector<int>& v2)
    {
        int n=v1.size(),m=v2.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        
        // i==0 OR j==0 we store nothing for base case to access dp[i-1][j-1] 
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                // dont be foolish and do v1[i]==v2[j]
                if(v1[i-1]==v2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                // max lcs till i-1 and j-1 indices of vectors v1 and v2
            }
        }
        return dp[n][m];
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        return solve(nums1,nums2);
    }
};