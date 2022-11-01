class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,0); // we have to reach n or from dp[n] to 0
        dp[n-1] = cost[n-1];
        dp[n-2] = cost[n-2]; // not min as if it has value of n-1, then we can make a wrong jump to n-2 instead of n-3
        // giving wrong answer
        
        
        for(int i=n-3;i>=0;i--)
        {
            dp[i] = min(dp[i+1], dp[i+2]) + cost[i];
        }
        // for(int i:dp)
        //     cout<<i<<" ";
        
        return min(dp[0],dp[1]);
    }
};
/*
this ques is same as climbing steps except you have to minimize the cost here
*/