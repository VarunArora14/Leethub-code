class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        
        m = len(rolls)
        netSum = mean*(m+n)
        
        remSum=netSum
        for r in rolls:
            remSum-=r
        
        print(remSum)
        # make sure that this remaining value can be put as values of n dice rolls
        if remSum<n or n*6<remSum:
            return []
        
        n_dices = [1 for _ in range(n)]
        remSum-=n
        i=0
        while i<n and remSum>0:
            if remSum>5:
                n_dices[i]=6
                remSum-=5
            else:
                n_dices[i]+=remSum
                remSum=0
            i+=1
        
        return n_dices