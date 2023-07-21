#include <vector>
#include <string>

std::string who_is_winner(std::vector<std::string> pieces_position_list) {
    // Create the board as a 6x7 matrix
    char board[6][7] = { { '.', '.', '.', '.', '.', '.', '.' },
                         { '.', '.', '.', '.', '.', '.', '.' },
                         { '.', '.', '.', '.', '.', '.', '.' },
                         { '.', '.', '.', '.', '.', '.', '.' },
                         { '.', '.', '.', '.', '.', '.', '.' },
                         { '.', '.', '.', '.', '.', '.', '.' } };

    // Play each move and update the board
    for (const std::string& move : pieces_position_list) {
        char color = move[2];
        int column = move[0] - 'A';
        int row = 5;
        while (board[row][column] != '.') {
            row--;
        }
        board[row][column] = color;
        
        // Check for a win
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                if (board[i][j] == color &&
                    (j + 3 < 7 && board[i][j+1] == color && board[i][j+2] == color && board[i][j+3] == color ||
                     i + 3 < 6 && board[i+1][j] == color && board[i+2][j] == color && board[i+3][j] == color ||
                     j + 3 < 7 && i + 3 < 6 && board[i+1][j+1] == color && board[i+2][j+2] == color && board[i+3][j+3] == color ||
                     j - 3 >= 0 && i + 3 < 6 && board[i+1][j-1] == color && board[i+2][j-2] == color && board[i+3][j-3] == color)) {
                    return color == 'R' ? "Red" : "Yellow";
                }
            }
        }
    }
    
    return "Draw";
}