class Solution:
    def isReachableAtTime(self, sx: int, sy: int, fx: int, fy: int, t: int) -> bool:
        x_dist = abs(sx - fx)
        y_dist = abs(sy - fy)

        if x_dist == 0 and y_dist == 0:
            return t != 1

        return x_dist <= t and y_dist <= t  
    
    # reason we need max of xdist, ydist is that consider n*m matrix and try to go diagonally
    # we can minimize distance on going diagonally which is x,y => x+1.y+1
    # now,to get to destination, we have to make sure larger value should be considered as threshold, consider 3X4 matrix
    # from top left to bottom right (takes 4 seconds)
    # Also consider horizontal and vertical cases as well(lines)
    
    # base cases can exist for fx=sx and sy=fy which ans is 1