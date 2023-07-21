#include <iostream>
#include <vector>

using namespace std;

bool find_word(const vector<vector<char>>& board, const string& word, int row, int col, int index, vector<vector<bool>>& visited) {
    // If the index of the current character is equal to the length of the word, we have found the word
    if (index == word.length()) {
        return true;
    }
    
    // Check if the current cell is a valid cell to explore
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || visited[row][col] || board[row][col] != word[index]) {
        return false;
    }
    
    // Mark the current cell as visited
    visited[row][col] = true;
    
    // Explore all the neighbouring cells
    bool found = false;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int next_row = row + i;
            int next_col = col + j;
            found = found || find_word(board, word, next_row, next_col, index + 1, visited);
        }
    }
    
    // Unmark the current cell as visited
    visited[row][col] = false;
    
    return found;
}

bool check_word(const vector<vector<char>>& board, const string& word) {
    // Check if the board or the word is empty
    if (board.empty() || board[0].empty() || word.empty()) {
        return false;
    }
    
    // Initialize the visited matrix to keep track of the cells that have been used in the current path
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    
    // Check if the word can be formed starting from each cell in the board
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (find_word(board, word, i, j, 0, visited)) {
                return true;
            }
        }
    }
    
    return false;
}