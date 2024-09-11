class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        start_str = bin(start)[2:]
        goal_str = bin(goal)[2:]
        
        if len(goal_str) > len(start_str):
            rem = len(goal_str) - len(start_str)
            start_str = '0'*rem + start_str
        else:
            rem = len(start_str) - len(goal_str)
            goal_str = '0'*rem + goal_str
        
        print(goal_str, start_str)
        counter=0
        for i in range(len(goal_str)):
            if goal_str[i]!=start_str[i]:
                counter+=1
        
        return counter