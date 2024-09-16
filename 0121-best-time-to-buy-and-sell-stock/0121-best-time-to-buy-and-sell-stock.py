class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        lowestPriceTillNow=prices[0]
        maxProfitTillNow=0
        n=len(prices)
        
        for i in range(1,n):
            if prices[i]<lowestPriceTillNow:
                lowestPriceTillNow=prices[i]
            maxProfitTillNow = max(maxProfitTillNow, prices[i]- lowestPriceTillNow)
        
        return maxProfitTillNow