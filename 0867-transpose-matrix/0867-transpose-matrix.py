class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        n = len(matrix)
        m = len(matrix[0])
        
        tmp = [[-1 for _ in range(n)] for _ in range(m)] # n*n matrix with -1
        
        for i in range(n):
            for j in range(m):
                tmp[j][i] = matrix[i][j]
        
        return tmp