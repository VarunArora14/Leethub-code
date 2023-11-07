class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        arrival = []
        for i in range(len(dist)):
            arrival.append(dist[i]/speed[i])
            
        arrival.sort()
        ans=0
        
        for i in range(len(arrival)):
            
            # monster arrives before recharge
            # at i=0, monster must be >0
            # then recharge and so at i=1, monster should take at least time=2(dist[i]/speed[i])
            if arrival[i] <=i :
                break
                
            ans+=1
        return ans