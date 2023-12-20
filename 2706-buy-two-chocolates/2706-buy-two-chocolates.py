class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        firstSmallest, secondSmallest = 101,101
        for i in prices :
            if i<firstSmallest:
                secondSmallest=firstSmallest
                firstSmallest=i
        
            elif i<secondSmallest :
                secondSmallest=i 
        if (firstSmallest+secondSmallest)>money :
            return money
        return money-(firstSmallest+secondSmallest)
        