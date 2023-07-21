function connectFour(board) {
  for (let row = 0; row < board.length; row++) {
    for (let col = 0; col < board[row].length - 3; col++) {
      if (
        board[row][col] !== '-' &&
        board[row][col] === board[row][col + 1] &&
        board[row][col] === board[row][col + 2] &&
        board[row][col] === board[row][col + 3]
      ) {
        return board[row][col];
      }
    }
  }

  for (let col = 0; col < board[0].length; col++) {
    for (let row = 0; row < board.length - 3; row++) {
      if (
        board[row][col] !== '-' &&
        board[row][col] === board[row + 1][col] &&
        board[row][col] === board[row + 2][col] &&
        board[row][col] === board[row + 3][col]
      ) {
        return board[row][col];
      }
    }
  }

  for (let row = 0; row < board.length - 3; row++) {
    for (let col = 0; col < board[row].length - 3; col++) {
      if (
        board[row][col] !== '-' &&
        board[row][col] === board[row + 1][col + 1] &&
        board[row][col] === board[row + 2][col + 2] &&
        board[row][col] === board[row + 3][col + 3]
      ) {
        return board[row][col];
      }
    }
  }

  for (let row = 0; row < board.length - 3; row++) {
    for (let col = 3; col < board[row].length; col++) {
      if (
        board[row][col] !== '-' &&
        board[row][col] === board[row + 1][col - 1] &&
        board[row][col] === board[row + 2][col - 2] &&
        board[row][col] === board[row + 3][col - 3]
      ) {
        return board[row][col];
      }
    }
  }

  for (let row = 0; row < board.length; row++) {
    if (board[row].includes('-')) {
      return 'in progress';
    }
  }

  return 'draw';
}