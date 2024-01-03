class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        su = 0
        a = []
        for i in range(len(bank)):
            count = 0
            for j in range(len(bank[i])):
                if bank[i][j]=='1':
                    count+=1
            if count>0:
                a.append(count) # only append next row if count > 0, avoids problem where next row had 0 devices
        if len(a)<=1:
            return 0
        else:
            for i in range(len(a)-1):
                su+=a[i]*a[i+1]
        return su