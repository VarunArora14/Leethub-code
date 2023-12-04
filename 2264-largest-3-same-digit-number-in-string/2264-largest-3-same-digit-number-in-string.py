class Solution:
    def largestGoodInteger(self, num: str) -> str:
        n = len(num)
        largestGood = ""
        
        for i in range(n-2):
            substr = num[i:i+3]
            
            if substr[0] == substr[1] == substr[2]:
                largestGood = largestGood if largestGood > substr else substr
        
        return largestGood