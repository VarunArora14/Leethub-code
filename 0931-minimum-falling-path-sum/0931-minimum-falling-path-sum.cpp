class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>> dp = matrix;
        
        
        if(matrix.size()==1) return *min_element(matrix[0].begin(), matrix[0].end());
        if(m==1){
            int minval = INT_MAX;
            for(int i=0;i<n;i++)
            {
                minval = min(minval, matrix[i][0]);
            }
            return minval;
        }
        
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j==0)
                {
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j], dp[i-1][j+1]);
                }
                else if(j==m-1)
                {
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
                }
                else dp[i][j] = matrix[i][j] + min({ dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1] });
            }
        }
        
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        
        return *min_element(dp[n-1].begin(), dp[n-1].end());
        
    }
};

// basically a DP problem like goldmine, at each step find the min and 
// dp[i][j] = nums[i][j] + min({ dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1] })