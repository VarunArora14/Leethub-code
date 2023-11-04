class Solution:
    def getLastMoment(self, n: int, left: List[int], right: List[int]) -> int:
        
        # here collisions are irrelevant as when ants collide, they take no time to change direction
        # if they were to pass by each other instead of colliding, it would have taken same time since 
        # all ants are same A and B colliding and swapping is same as A and B not colliding and moving
        
        # find the longest time from left to start(0) from RIGHT to LEFT (maximum)
        # find the longest time taken from start(0) to end by from LEFT to RIGHT (minimum value to start)
        
        ans=0
        
        for item in left:
            ans = max(ans,item) # item is start and destination is 0
        
        for item in right:
            ans = max(ans, n-item) # n-item as item is position of start to destination n
        
        return ans