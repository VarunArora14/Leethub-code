class Solution:
    def minOperations(self, nums: List[int]) -> int:
        mapper = {}
        for num in nums:
            if num not in mapper:
                mapper[num]=1
            else:
                mapper[num]+=1
        
        res=0
        for key,val in mapper.items():
            if val==1:
                return -1
            elif val%3==0:
                res+=val/3
            elif val%3==2:
                res+=1+(val-2)/3
            else:
                res+=2 + (val-4)/3 # for cases val>=4, we find if we substract 4, we get multiple of 3
        return int(res)