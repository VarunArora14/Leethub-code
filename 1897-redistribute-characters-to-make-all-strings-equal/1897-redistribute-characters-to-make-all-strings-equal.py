class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        mapper = {}
        for word in words:
            for char in word:
                if char not in mapper:
                    mapper[char]=1
                else:
                    mapper[char]+=1
        
        
# if n words exist, check if each occurence is a multiple of n
        n = len(words)
        for val in mapper.values():
            if val%n!=0:
                return False
        
        return True