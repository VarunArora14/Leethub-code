class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        
        # st = [i for i in range(1,n+1)]
        # print(st)
        res=[]
        
        c=0
        i=0
        while i<len(target):
            if c+1 == target[i]:
                i+=1
                c+=1
                res.append("Push")
            else:
                while target[i] > c+1:
                    res.append("Push")
                    res.append("Pop")
                    c+=1
        
        return res
            