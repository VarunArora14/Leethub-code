class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        #1) Make a ratio of Speed/Dist to tell you which to shoot first
        #2) Shoot highest ratio monster
        #3) Add the new speeds to the distance
        #4) If any distances are <=0 then you lose --> berak
        #else repeat steps 2-4 until break
        monsters_shot = 0
        ratio = [y/x for x, y in zip(speed, dist)]
        ratio.sort()

        for i in range(len(dist)):
            if ratio[i] > i:
                monsters_shot +=1
            else:
                break
        return monsters_shot