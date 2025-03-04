class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)-1

        for i in range(n//2 +1):
            for j in range(i,n-i):
                pivot = matrix[j][n-i]

                matrix[j][n-i] = matrix[i][j]
                matrix[i][j]= matrix[n-j][i]
                matrix[n-j][i] = matrix[n-i][n-j]
                matrix[n-i][n-j]=pivot