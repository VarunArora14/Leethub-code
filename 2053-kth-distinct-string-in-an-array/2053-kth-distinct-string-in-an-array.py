class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        mapper = {}
        for s in arr:
            if s not in mapper:
                mapper[s]=0
            mapper[s]+=1
        
        for s in arr:
            if k==1 and mapper[s]==1:
                return s
            elif k>1 and mapper[s]==1:
                k-=1
            else:
                continue
        return ""