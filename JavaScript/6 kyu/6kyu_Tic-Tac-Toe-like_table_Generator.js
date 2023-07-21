function displayBoard(board, width){
  let result = '';
  let currentCol = 0;

  for (let i=0;i<board.length;i++) {
    const element = board[i];
    result += ` ${element} ${currentCol===(width - 1) ? '\n' : '|'}`;
    currentCol++;
    if (currentCol == width) {
      currentCol = 0;
      if (i !== board.length-1) {
        result+='-'.repeat((width * 3)+(width-1))+'\n';
      }
    }
  }
  result = result.slice(0, -1);
  return result;
}