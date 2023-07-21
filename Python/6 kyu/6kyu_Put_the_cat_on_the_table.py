from collections import deque

def put_the_cat_on_the_table(cat, room):
    cat_row, cat_col = cat[0], cat[1]
    num_rows = len(room)
    num_cols = len(room[0])

    if cat_row < 0 or cat_row >= num_rows or cat_col < 0 or cat_col >= num_cols:
        return "NoCat"
    if not any(1 in row for row in room):
        return "NoTable"
    if room[cat_row][cat_col] == 1:
        return ""
    
    directions = [(1, 0, 'D'), (-1, 0, 'U'), (0, 1, 'R'), (0, -1, 'L')]

    queue = deque([(cat_row, cat_col, '')])
    visited = set([(cat_row, cat_col)])

    while queue:
        row, col, route = queue.popleft()

        for dx, dy, direction in directions:
            new_row = row + dx
            new_col = col + dy

            if (
                new_row >= 0
                and new_row < num_rows
                and new_col >= 0
                and new_col < num_cols
                and (new_row, new_col) not in visited
            ):
                if room[new_row][new_col] == 1:
                    return route + direction
                else:
                    queue.append((new_row, new_col, route + direction))
                    visited.add((new_row, new_col))

    return "NoTable"  # If the table is not reachable