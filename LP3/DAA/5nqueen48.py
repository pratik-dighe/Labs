
def is_safe(board, row, col, n):
    # Check the left side of the current column
    for i in range(col):
        if board[row][i] == 1:
            return False
        
    # Check upper diagonal on the left side
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    # Check lower diagonal on the left side
    for i, j in zip(range(row, n, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True

def solve_n_queens(board, col, n):
    if col >= n:
        return True

    for i in range(n):
        if is_safe(board, i, col, n):
            board[i][col] = 1

            if solve_n_queens(board, col + 1, n):
                return True

            board[i][col] = 0
        # print("I ", i, col)
    return False

def print_board(board):
    for row in board:
        print(" ".join(["Q" if x else "." for x in row]))

def main():
    n = int(input("Enter the value of N: "))
    board = [[0 for _ in range(n)] for _ in range(n)]

    # Get the user's choice of starting position (i, j)
    # i = int(input("Enter the row (0 to {}): ".format(n-1)))
    # j = int(input("Enter the column (0 to {}): ".format(n-1)))

    # if i < 0 or i >= n or j < 0 or j >= n:
    #     print("Invalid starting position.")
    #     return

    # board[i][j] = 1

    # if solve_n_queens(board, j + 1, n):
    if solve_n_queens(board, 0, n):
        print("Solution found:")
        print_board(board)
    else:
        print("No solution exists.")

if __name__ == "__main__":
    main()
   
    
'''
1. Check if Placement is Safe
The is_safe function checks if placing a queen at a specific position (row, col) on the board is safe.

Check Left Side: It first checks the left side of the current row to see if any queen is already placed in that row.

Check Upper Diagonal: Then it checks the upper diagonal on the left side to see if any queen threatens the position diagonally.

Check Lower Diagonal: Finally, it checks the lower diagonal on the left side for threats.

If any of these checks find a queen, it returns False; otherwise, it returns True, indicating the position is safe.

2. Solve the N-Queens Problem
The solve_n_queens function attempts to place queens column by column.

Base Case: If the current column (col) is greater than or equal to N, it means all queens are successfully placed, so it returns True.

Try Each Row: It loops through each row to find a safe position for a queen in the current column.

If a safe position is found, it places a queen (sets board[i][col] to 1).
It then recursively calls itself to place queens in the next column.
If placing the queen leads to a solution, it returns True.
If not, it backtracks by removing the queen (setting board[i][col] back to 0) and tries the next row.
3. Print the Board
The print_board function displays the board. It prints "Q" for queens and "." for empty spaces.

4. Main Function
The main function is the starting point of the program.

It prompts the user to enter the size of the board (N).
It initializes an empty board (a 2D list filled with zeros).
It calls solve_n_queens to try to find a solution.
If a solution is found, it prints the board; if not, it informs the user that no solution exists.
5. Execution
The last part of the code checks if the script is being run directly. If so, it calls the main function to start the program.
'''    