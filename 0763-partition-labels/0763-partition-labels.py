#https://leetcode.com/problems/partition-labels/discuss/1868842/JavaC%2B%2B-VISUALLY-EXPLAINEDDDDD!!

class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        
        mapper = {}
        
        for i,char in enumerate(s):
            if char not in mapper:
                mapper[char]=0
            mapper[char]=i # stores the last pos of each character
        
        seg_end_maxval=0
        oldpos=0
        counter_arr = []
        for i in range(len(s)):
            seg_end_maxval = max(seg_end_maxval, mapper[s[i]])
            if seg_end_maxval == i:
                # case when we have reached the last occurence of character and characters before that as well
                counter_arr.append(i-oldpos+1)
                oldpos=i+1 # for next segment
        
        return counter_arr