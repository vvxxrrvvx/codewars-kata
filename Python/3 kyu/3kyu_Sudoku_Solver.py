def is_valid(puzzle, row, col, num):
    """
    Returns True if num can be placed in the given cell without violating the Sudoku rules.
    """
    # Check row
    for i in range(9):
        if puzzle[row][i] == num:
            return False
    # Check column
    for i in range(9):
        if puzzle[i][col] == num:
            return False
    # Check box
    box_row = row // 3 * 3
    box_col = col // 3 * 3
    for i in range(3):
        for j in range(3):
            if puzzle[box_row+i][box_col+j] == num:
                return False
    return True


def solve_sudoku(puzzle):
    """
    Solves the given Sudoku puzzle using backtracking.
    Returns True if the puzzle is solved and False otherwise.
    """
    for row in range(9):
        for col in range(9):
            if puzzle[row][col] == 0:
                for num in range(1, 10):
                    if is_valid(puzzle, row, col, num):
                        puzzle[row][col] = num
                        if solve_sudoku(puzzle):
                            return True
                        puzzle[row][col] = 0
                return False
    return True

def sudoku(puzzle):
    """
    Returns the solved puzzle as a 2d array of 9 x 9.
    """
    # Make a copy of the puzzle
    puzzle_copy = [row[:] for row in puzzle]
    # Solve the puzzle
    if solve_sudoku(puzzle_copy):
        return puzzle_copy
    else:
        return puzzle