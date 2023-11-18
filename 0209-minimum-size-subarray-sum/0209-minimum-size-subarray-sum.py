class Solution:
    def minSubArrayLen(self, target: int, arr: List[int]) -> int:
        if arr ==[]:
            return 0

        resLen = 1e9+7
        i=0
        currSum=0
        for j in range(0, len(arr)):
            currSum+=arr[j]
            print(currSum)
            if currSum >= target:
                print(f"currSum: {currSum}, j: {j}, i: {i}")
                resLen = min(resLen, j-i+1)

                while j>=i and currSum - arr[i] >=target:
                    currSum-=arr[i]
                    i+=1
                    resLen = min(resLen, j-i+1)

            # print(f"i: {i}, j: {j}, resLen: {resLen}")

        return resLen if resLen !=1e9+7 else 0