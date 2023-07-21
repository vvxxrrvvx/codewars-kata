def knight(p1, p2):
    # convert positions to coordinates
    x1, y1 = ord(p1[0]) - 97, int(p1[1]) - 1
    x2, y2 = ord(p2[0]) - 97, int(p2[1]) - 1

    # possible moves of a knight
    moves = [(2, 1), (1, 2), (-1, 2), (-2, 1),
             (-2, -1), (-1, -2), (1, -2), (2, -1)]

    # use BFS to find shortest path
    queue = [(x1, y1, 0)]
    visited = set([(x1, y1)])
    while queue:
        x, y, steps = queue.pop(0)
        if x == x2 and y == y2:
            return steps
        for dx, dy in moves:
            new_x, new_y = x + dx, y + dy
            if 0 <= new_x < 8 and 0 <= new_y < 8 and (new_x, new_y) not in visited:
                queue.append((new_x, new_y, steps + 1))
                visited.add((new_x, new_y))

    # if no path found
    return -1