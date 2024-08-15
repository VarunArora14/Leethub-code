class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        fives,tens, twenties = 0,0,0
        
        for b in bills:
            if b==5:
                fives+=1
            elif b==10:
                if fives==0:
                    return False
                else:
                    fives-=1
                    tens+=1
            else:
                if tens==0:
                    if fives<3:
                        return False
                    else:
                        fives-=3
                else:
                    if fives==0:
                        return False
                    else:
                        tens-=1
                        fives-=1
        return True