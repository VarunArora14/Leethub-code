class Solution:
    def findOneBit(self,a:int)->int:
            count = 0
            while a > 0:
                if a & 1:
                    count += 1
                a = a >> 1  # right shift 1 bit
            return count
        
    def sortByBits(self, arr: List[int]) -> List[int]:
        # pow(2,13) is largest element smaller than 1e4, so we need 14 items till 1e4
        # create 13 element array to represent count of 1s and store elements(like hash table)
        store = [[] for _ in range(14)]
        
        for ele in arr:
            c = self.findOneBit(ele)
            store[c].append(ele)
        
        res=[]
        for s in store:
            s.sort()
            for single_s in s:
                res.append(single_s)
        return res