class Solution:
    def numDecodings(self, s:str) -> int:
        if len(s) == 0 or s is None:
            return 0

        @lru_cache(maxsize=None)
        def dfs(string):
            
            # base cases
            if len(string)>0:
                if string[0] == '0':
                    return 0
            if string == "" or len(string) == 1:
                return 1
            
            # if number < 26, we can have 2 options
            if int(string[0:2]) <= 26:
                first = dfs(string[1:]) # pass the remaining substring till it goes to base case
                second = dfs(string[2:])
                return first+second
            else:
                return dfs(string[1:])

        result_sum = dfs(s)

        return result_sum