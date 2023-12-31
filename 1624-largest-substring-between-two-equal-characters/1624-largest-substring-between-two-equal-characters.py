class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        hmap = defaultdict(int)
        res = -1
        for i, a in enumerate(s):
          if a not in hmap:
            hmap[a] = i # store the first occurence
          else:
            res = max(res, i-hmap[a]-1) # find the len if it occurs again
        return res