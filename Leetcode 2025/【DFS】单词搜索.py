class Solution:
    def dfs(self, board, word, visited, i, j, word_pos):
        if (i<0 or i>= len(board) or j <0 or j>=len(board[0])) or visited[i][j] or board[i][j]!=word[word_pos]:
            return False
        
        if word_pos == len(word)-1:
            return True

        visited[i][j]=True

        if (self.dfs(board, word, visited, i + 1, j, word_pos + 1) or 
            self.dfs(board, word, visited, i - 1, j, word_pos + 1) or
            self.dfs(board, word, visited, i , j+1, word_pos + 1) or
            self.dfs(board, word, visited, i , j-1, word_pos + 1) ): 
            return True

        visited[i][j] =False
        return False
    
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])

        visited = [[False for _ in range(n)] for __ in range(m)]

        return any([self.dfs(board, word, visited, i, j, 0) for i in range(m) for j in range(n) ])