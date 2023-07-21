const Sudoku = function(data) {
  const n = data.length;

  function isValidUnit(unit) {
    const validNumbers = new Set([...Array(n)].map((_, i) => i + 1));
    const unitNumbers = new Set(unit);
    return unitNumbers.size === n && [...unitNumbers].every(x => validNumbers.has(x));
  }

  function getUnit(row, col) {
    const size = Math.sqrt(n);
    const unit = [];

    for (let i = 0; i < size; i++) {
      for (let j = 0; j < size; j++) {
        unit.push(data[Math.floor(row / size) * size + i][Math.floor(col / size) * size + j]);
      }
    }

    return unit;
  }

  return {
    isValid() {
      // Check rows, columns, and little squares
      for (let i = 0; i < n; i++) {
        if (!isValidUnit(data[i]) || !isValidUnit(data.map(row => row[i])) || !isValidUnit(getUnit(i, i))) {
          return false;
        }
      }
      return true;
    }
  };
};