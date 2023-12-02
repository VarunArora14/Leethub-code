class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        mapper = dict()
        res=0
        
        for c in chars:
            if c in mapper:
                mapper[c]+=1
            else:
                mapper[c]=1
        
        for w in words:
            m = dict()
            for char in w:
                if char in m:
                    m[char]+=1
                else:
                    m[char]=1
            flag=True
            for key, val in m.items():
                if (key not in m) or (key not in mapper) or (val > mapper[key]):
                    flag=False
            
            if flag==True:
                res+=len(w)
        
        return res