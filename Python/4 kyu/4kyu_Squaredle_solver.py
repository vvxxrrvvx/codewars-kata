from preloaded import WORDS

class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_word = False

def build_trie(words):
    root = TrieNode()
    for word in words:
        current = root
        for char in word:
            if char not in current.children:
                current.children[char] = TrieNode()
            current = current.children[char]
        current.is_word = True
    return root

def is_valid_position(puzzle, visited, row, col):
    num_rows = len(puzzle)
    num_cols = len(puzzle[0])

    if row < 0 or row >= num_rows or col < 0 or col >= num_cols:
        return False

    if visited[row][col]:
        return False

    return True

def find_words(puzzle, visited, row, col, current_word, node, words):
    num_rows = len(puzzle)
    num_cols = len(puzzle[0])

    visited[row][col] = True
    current_word += puzzle[row][col]

    if node.is_word:
        words.add(current_word)

    # Possible movements in all eight directions
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (-1, 1), (1, -1), (1, 1)]

    for dr, dc in directions:
        new_row = row + dr
        new_col = col + dc

        if is_valid_position(puzzle, visited, new_row, new_col) and puzzle[new_row][new_col] in node.children:
            find_words(puzzle, visited, new_row, new_col, current_word, node.children[puzzle[new_row][new_col]], words)

    visited[row][col] = False

def squaredle(puzzle):
    rows = puzzle.split('-')
    num_rows = len(rows)
    num_cols = len(rows[0])

    visited = [[False] * num_cols for _ in range(num_rows)]
    words = set()
    root = build_trie(WORDS)

    for row in range(num_rows):
        for col in range(num_cols):
            if rows[row][col] in root.children:
                find_words(rows, visited, row, col, '', root.children[rows[row][col]], words)

    result = sorted(words, key=lambda x: (len(x), x))
    return result