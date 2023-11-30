class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        
        sortedJobs = sorted(zip(difficulty, profit), key = lambda x: x[0]) # smallest to largest difficulty
        res=i=best=0
        # resArr = []
        
        # sort worker to go to max skill storing the best
        for workerSkill in sorted(worker):
            while i<len(sortedJobs) and workerSkill>=sortedJobs[i][0]:
                best=max(best, sortedJobs[i][1])
                i+=1
            res+=best
            # resArr.append(best)
        
        # print(resArr)
        return res