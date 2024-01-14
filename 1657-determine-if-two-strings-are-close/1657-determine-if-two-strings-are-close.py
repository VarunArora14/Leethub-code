# if len is diff and no unique chars exist in any of those
class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if len(word1)!=len(word2):
            return False
        
        first_set = set()
        second_set = set()
        
        
        for char in word1:
            first_set.add(char)
        
        for char in word2:
            second_set.add(char)
        
        for char in word1:
            if char not in second_set:
                return False
        
        for char in word2:
            if char not in first_set:
                return False
        
        # consider case aaza and zzaa, they cannot be correct as occurences differ of z and a and cannot be swapped 
        # store the frequencies and then see if we have no different frequencies which we cannot swap as above
        # example of [3,1] and [2,2]
        
        f1 = [0 for _ in range(26)]
        f2 = [0 for _ in range(26)]
        
        for i in range(len(word1)):
            char = word1[i]
            f1[ord(char)-97]+=1
            char = word2[i]
            f2[ord(char)-97]+=1
        
        if sorted(f1)!=sorted(f2):
            return False
        
        
        return True