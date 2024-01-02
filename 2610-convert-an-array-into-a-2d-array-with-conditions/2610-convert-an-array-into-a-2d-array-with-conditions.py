class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        mapper = {}
        for num in nums:
            if num not in mapper:
                mapper[num]=1
            else:
                mapper[num]+=1
        
        res= []
        for i in range(max(mapper.values())):
            row = []
            for key, value in mapper.items():
                if value>0:
                    row.append(key)
                    mapper[key]-=1
            if row!=[]:
                res.append(row)
        
        return res
            