class Solution:
    def reductionOperations(self, nums: List[int]) -> int:
        tdict = {}

        for n in nums:
            if n in tdict:
                tdict[n]+=1
            else:
                tdict[n]=1

        q = []

        for key, val in tdict.items():
            heapq.heappush(q, (-key,val))

        counter=0
        while len(q)>1:
            (tkey, tval) = heapq.heappop(q)
            (slKey, slVal) = heapq.heappop(q)

            slVal+=tval
            counter+=tval
            heapq.heappush(q, (slKey, slVal))
        
        return counter