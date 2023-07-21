USE_BREAK_DISPLAY = True

def break_pieces(shape):
    if not shape.strip():
        return []

    (rows, cols, shape) = interpolate(shape)

    # store the tuples where there is an empty space
    empty_spaces = {(row, col) for row in range(rows) for col in range(cols) if shape[row][col] == ' '}
    regions = []
    while empty_spaces:
        R = {empty_spaces.pop()}
        row_empty_neighbors = R
        while row_empty_neighbors:
            # store all empty neighbor relative to an empty space
            row_empty_neighbors = {j for i in row_empty_neighbors for j in neighbor(i) & empty_spaces} - R
            R.update(row_empty_neighbors)
        empty_spaces = empty_spaces - R

        boundary = {j for i in R for j in neighbor8(i)} - R
        min_row = min(row for row, col in boundary)
        max_row = max(row for row, col in boundary) + 1
        min_col = min(col for row, col in boundary)
        max_col = max(col for row, col in boundary) + 1

        if min_row < 0 or min_col < 0 or max_row > rows or max_col > cols:
            continue

        region = [list(row[min_col:max_col]) for row in shape[min_row:max_row]]

        for row in range(len(region)):
            for col in range(len(region[row])):
                if region[row][col] != ' ' and (row + min_row, col + min_col) not in boundary:
                    region[row][col] = ' '
                elif region[row][col] == '+':
                    c = (row + min_row, col + min_col)
                    if not (horizontal_neightbor(c) & boundary and vertical_neightbor(c) & boundary):
                        region[row][col] = '-' if horizontal_neightbor(c) & boundary else '|'
        regions.append('\n'.join(''.join(row[::2]).rstrip() for row in region[::2]))
    return regions


    
def interpolate(s):
    # store an array with each row
    shape = s.split('\n')
    
    while not shape[0].strip():
        shape = shape[1:]
    while not shape[-1].strip():
        shape = shape[:-1]

    lines = len(shape)
    max_len_line = max(len(shape[line]) for line in range(lines))

    # add to each row a number of space
    # so that each row has the same length
    for row in range(lines):
        shape[row] += ' ' * (max_len_line - len(shape[row]))
    
    # Create an empty canvas to work on
    # 2 * lines - 1 => rows
    # 2 * max_len_line - 1 => columns
    new_shape = [[]] * (2 * lines - 1)

    for row in range(2 * lines - 1):
        new_shape[row] = [' '] * (2 * max_len_line - 1)
        # if it is an odd row
        if row % 2:
            # for each column
            for col in range(max_len_line):
                # if the shape value is wall '|' or an intersection '+' 
                if shape[row // 2][col] in '|+' and shape[row // 2 + 1][col] in '|+':
                    # the new shape will store an wall '|'
                    new_shape[row][2 * col] = '|'
        # if it is an even row
        else:
            # for each column
            for col in range(2 * max_len_line - 1):
                # if it is an even col
                if col % 2:
                    # if the shape value is a roof/floor '-' or an intersection '+'
                    if shape[row // 2] [col // 2] in '-+' and shape[row // 2][col // 2 + 1] in '-+':
                        # the new shape will store a roof/floor
                        new_shape[row][col] = '-'
                else:
                    # store the correspondent value in the original shape
                    new_shape[row][col] = shape[row // 2][col // 2]
    return 2 * lines - 1, 2 * max_len_line - 1, new_shape

# for a given tuple, return it N E W S neighbors
neighbor = lambda col: {(col[0] + 1, col[1]), (col[0] - 1, col[1]), (col[0], col[1] + 1), (col[0], col[1] - 1)}

# for a given tuple, return it N E W S NE NW SE SW neighbors
neighbor8 = lambda c: {(c[0] + i, c[1] + j) for i in {1, -1, 0} for j in {1, -1, 0}}

# for a given tuple, return it N S neighbors
vertical_neightbor = lambda c: {(c[0] + 1, c[1]), (c[0] - 1, c[1])}

# for a given tuple, return it E W neighbors
horizontal_neightbor = lambda c: {(c[0], c[1] + 1), (c[0], c[1] - 1)}
2 hours agoRefactorDiscuss
3 kyu
The Millionth Fibonacci Kata
Python:
def mul(mat1, mat2):
    mat3 = []
    for i in range(2):
        r = []
        for j in range(2):
            t = 0
            for k in range(2):
                t += mat1[i][k] * mat2[k][j]
            r.append(t)
        mat3.append(r)
    return mat3

def fib(n):
    r = [[1, 0], [0, 1]]
    t = [[0, 1], [1, 1]]
    if n < 0:
        n = -n
        t = [[-1, 1], [1, 0]]
    while n > 0:
        if (n & 1) > 0:
            r = mul(t, r)
        t = mul(t, t)
        n >>= 1
    return r[0][1]