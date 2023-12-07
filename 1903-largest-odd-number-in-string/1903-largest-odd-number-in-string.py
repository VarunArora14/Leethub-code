class Solution:
    def largestOddNumber(self, num: str) -> str:
        pos=-1
        
        for idx, n in enumerate(num):
            if int(n)%2!=0:
                pos = idx+1
        
        if pos==-1:
            return ""
        
        else:
            return num[:pos]
                