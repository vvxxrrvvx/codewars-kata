from typing import List

def is_prime(num: int) -> bool:
    """Check if a number is prime."""
    if num < 2:
        return False
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            return False
    return True

def get_valid_neighbors(num: int) -> List[int]:
    """Get valid neighbors of a number by changing a single digit."""
    neighbors = []
    str_num = str(num)
    for i in range(4):
        for digit in range(10):
            new_num = int(str_num[:i] + str(digit) + str_num[i + 1:])
            if new_num != num and is_prime(new_num) and len(str(new_num)) == 4:
                neighbors.append(new_num)
    return neighbors

def find_shortest_path(start: int, end: int) -> List[int]:
    """Find the shortest path betwixt two four-digit prime numbers."""
    if start == end:
        return [start]

    visited = set()
    queue = [(start, [start])]

    while queue:
        current, path = queue.pop(0)
        visited.add(current)

        neighbors = get_valid_neighbors(current)
        for neighbor in neighbors:
            if neighbor == end:
                return path + [end]
            if neighbor not in visited:
                queue.append((neighbor, path + [neighbor]))

    return []