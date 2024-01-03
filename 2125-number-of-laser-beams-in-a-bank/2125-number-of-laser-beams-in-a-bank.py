# if a row has 1 or more security devices, find for each row by going down if there exists a beam or not
class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        if len(bank)==1:
            return 0

        bank.reverse()

        strlen = len(bank[0])
        rowFlagArr = [False for _ in range(strlen)]

        res=0

        for row in range(len(bank)):
            string = bank[row]
            currRowDevices=0
            currRowDevices = string.count("1")
            for i in rowFlagArr:
                # security device found at 
                if i==True:
                    res+=currRowDevices # all devices in current row get added if any next row
            if currRowDevices > 0:
                currRowFlagArr = [False for _ in range(strlen)]
                for i in range(len(string)):
                    if string[i]=="1":
                        currRowFlagArr[i]=True
                    else:
                        currRowFlagArr[i] = False
                rowFlagArr = currRowFlagArr

        return res