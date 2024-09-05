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
        remSum-=n # assign all dices as default 1
        
        i=0
        while i<n and remSum>0:
            n_dices[i]+=min(5, remSum)
            remSum-=min(5, remSum)
            i+=1
        
        return n_dices