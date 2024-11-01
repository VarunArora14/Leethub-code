class Solution(object):
    def makeFancyString(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s)
        
        res=[]
        for char in s:
            if len(res)<2 or not (res[-1]==res[-2]==char):
                res.append(char)
        return ''.join(res)