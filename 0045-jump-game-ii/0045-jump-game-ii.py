class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [float('inf') for _ in range(len(nums))]
        dp[n-1]=1 # we have to reach this destination
        
        for i in range(n-2,-1,-1):
            j=0
            while i+j<n and j<=nums[i]:
                dp[i] = min(dp[i], 1 + dp[i+j])
                j+=1
        print(dp)
        return dp[0]-1