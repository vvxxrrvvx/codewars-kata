function dblLinear(n) {
  const sequence = [1];
  const seen = {};
  let length = 0;
  let xIndex = 0;
  while(length < n) {
    const x = sequence[xIndex];
    const y = 2 * x + 1;
    if (!seen[y]) {
      for (var i = sequence.length - 1; i >= 0; i--) {
        if (sequence[i] < y) {
          break;
        }
      }
      sequence.splice(i + 1, 0, y);
      seen[y] = true;
    }
    const z = 3 * x + 1;
    sequence.push(z);
    seen[z] = true;
    length++;    
    xIndex++;
  }
  return sequence[n];
}

function dblLinear(n) {
  const sequence = [1];
  const seen = {};  
  let length = 0;
  let last = 0;
  
  while (length < n) {
    const x = sequence.shift();
    delete seen[x];    
    const y = 2 * x + 1;    
    if (!seen[y]) {
      for (var i = last; i < sequence.length; i++) {
        if (sequence[i] > y) {
          break;
        }
      }
      sequence.splice(i, 0, y);
      seen[y] = true;
      last = i;
    }    
    const z = 3 * x + 1;    
    sequence.push(z);
    seen[z] = true;    
    length++;
  }
  return sequence[0]; 
}