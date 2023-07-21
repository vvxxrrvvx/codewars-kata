function validateBattlefield(field) {
    var hit = (row, col) => (row < 0 || col < 0 || row > 9 || col > 9) ? 0 : field[row][col];
    for (var ships = [10,0,0,0,0], row = 0; row < 10; row++) {
      for (var col = 0; col < 10; col++) {
        if ( hit(row,col) ) {
          if ( hit(row-1, col-1) || hit(row-1, col+1) ) return false; 
          if ( hit(row-1, col  ) && hit(row  , col-1) ) return false; 
          if ( ( field[row][col] += hit(row-1, col) + hit(row, col-1) ) > 4 ) return false;
          ships[field[row][col]]++; ships[field[row][col] - 1]--;
    } } }
    return [0,4,3,2,1].every((s,i) => s == ships[i]);
  }