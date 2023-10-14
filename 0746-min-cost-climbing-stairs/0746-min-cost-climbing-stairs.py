class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = [1001 for _ in range(len(cost))]
        l = len(cost)
        dp[l-1] = cost[l-1]
        dp[l-2] = cost[l-2]
        
        # traverse array backwards to 0th element in reverse from n-3
        for i in range(l-3, -1, -1):
            dp[i] = min(dp[i+1],dp[i+2]) + cost[i]
        
        return min(dp[0], dp[1])