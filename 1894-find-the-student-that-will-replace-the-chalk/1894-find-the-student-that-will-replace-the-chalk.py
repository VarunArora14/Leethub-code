class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        
        n = len(chalk)
        i=0
        chalksum=0
        for c in chalk:
            chalksum+=c
        k = k%chalksum
        while k>=0:
            # print(k)
            if chalk[i]>k:
                return i
            k-=chalk[i]
            i=(i+1)%n
        
        return -1