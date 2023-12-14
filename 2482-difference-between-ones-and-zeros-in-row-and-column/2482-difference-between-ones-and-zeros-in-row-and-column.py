class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        
        onesRow = [0 for _ in range(len(grid))]
        zerosRow = [0 for _ in range(len(grid))]
        onesCol = [0 for _ in range(len(grid[0]))]
        zerosCol = [0 for _ in range(len(grid[0]))]
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                onesRow[i]+= grid[i][j]==1
                onesCol[j]+= grid[i][j]==1
                zerosCol[j]+= grid[i][j]==0
                zerosRow[i]+= grid[i][j]==0
        
#         print(onesRow)
#         print(zerosCol)
#         print(zerosRow)
#         print(onesCol)
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                grid[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j]
        
        return grid