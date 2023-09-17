import random

def isValid(board, row, col, num):
    # 检查行是否满足规则
    for i in range(9):
        if board[row][i] == num:
            return False
    # 检查列是否满足规则
    for i in range(9):
        if board[i][col] == num:
            return False
    # 检查小九宫格是否满足规则
    startRow = 3 * (row // 3)
    startCol = 3 * (col // 3)
    for i in range(3):
        for j in range(3):
            if board[startRow + i][startCol + j] == num:
                return False
    return True

def solveSudoku(board):
    for row in range(9):
        for col in range(9):
            if board[row][col] == '.':
                for num in range(1, 10):
                    if isValid(board, row, col, str(num)):
                        board[row][col] = str(num)
                        if solveSudoku(board):
                            return True
                        board[row][col] = '.'  # 回溯
                return False  # 所有数字都尝试过都不符合规则，返回False
    return True  # 所有空格都填满了，返回True

def generateSudoku():
    board = [['.' for _ in range(9)] for _ in range(9)]
    for _ in range(20):
        row = random.randint(0, 8)
        col = random.randint(0, 8)
        num = random.randint(1, 9)
        while not isValid(board, row, col, str(num)):
            num = random.randint(1, 9)
        board[row][col] = str(num)
    return board

# 生成随机数独题目
sudoku = generateSudoku()

# 打印题目
for row in sudoku:
    print(row)

# 解决数独题目
solveSudoku(sudoku)

# 打印解答
print("Solution:")
for row in sudoku:
    print(row)