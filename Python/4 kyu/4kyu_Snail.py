ef snail(snail_map):
    if not snail_map or not snail_map[0]:
        return []

    result = []
    n = len(snail_map)
    row, col = 0, -1

    while True:
        # Traverse right
        for i in range(n):
            col += 1
            result.append(snail_map[row][col])
        n -= 1
        if n == 0:
            break

        # Traverse down
        for i in range(n):
            row += 1
            result.append(snail_map[row][col])

        # Traverse left
        for i in range(n):
            col -= 1
            result.append(snail_map[row][col])
        n -= 1
        if n == 0:
            break

        # Traverse up
        for i in range(n):
            row -= 1
            result.append(snail_map[row][col])

    return result