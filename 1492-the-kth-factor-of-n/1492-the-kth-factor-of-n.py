class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        
        factors = []
        count=0
        for i in range(1, n//2+1):
            if n%i==0:
                count+=1
                if count==k:
                    return i
        print(count)
        return n if count==k-1 else -1