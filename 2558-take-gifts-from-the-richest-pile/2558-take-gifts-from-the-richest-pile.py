import heapq

class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        q = []
        for g in gifts:
            heapq.heappush(q,-g)
        
        while len(q) and k>0:
            top = -heapq.heappop(q)
            print("top",top)
            if top==1:
                return len(q)+1
            heapq.heappush(q, -int(top**0.5))
            k-=1
        
        # print(q)
        res=0
        for ele in q:
            res+=ele
        return -res