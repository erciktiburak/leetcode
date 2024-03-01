from typing import List

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def is_safe(board, row, col):
            for i in range(row):
                if board[i][col] == 'Q':
                    return False
                if col-row+i >= 0 and board[i][col-row+i] == 'Q':
                    return False
                if col+row-i < len(board) and board[i][col+row-i] == 'Q':
                    return False
            return True

        def backtrack(board, row):
            if row == len(board):
                result.append(["".join(row) for row in board])
                return
            for col in range(len(board)):
                if is_safe(board, row, col):
                    board[row][col] = 'Q'
                    backtrack(board, row+1)
                    board[row][col] = '.'

        result = []
        board = [['.' for _ in range(n)] for _ in range(n)]
        backtrack(board, 0)
        return result

# Example usage
n = 4
solution = Solution()
print(solution.solveNQueens(n))


""" 
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 """