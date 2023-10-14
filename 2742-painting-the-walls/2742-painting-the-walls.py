class Solution:
    def paintWalls(self, cost: List[int], time: List[int]) -> int:
        l = len(cost)
        dp = [float('inf') for _ in range(l+1)]
        
        dp[0]=0 # cost to paint 0 walls
        
        for c,t in zip(cost,time):
            for j in range(l,0,-1):
                dp[j] = min(dp[j], c + dp[max(j-t-1,0)])
        
        return dp[l]
        