function compare(a, b, flipResult = false) {
  if (a[0] === '-' && b[0] !== '-') {
    return 'less';
  } else if (b[0] === '-' && a[0] !== '-') {
    return 'greater';
  } else if (a[0] === '-' && b[0] === '-') {
    flipResult = true;
    a = a.slice(1);
    b = b.slice(1);
  }

  while (a[0] === '0') {
    a = a.slice(1);
  }

  while (b[0] === '0') {
    b = b.slice(1);
  }

  let aDecimal;
  let bDecimal;
  [a, aDecimal = ''] = a.split('.');
  [b, bDecimal = ''] = b.split('.');

  if (a.length > b.length) return flipResult ? 'less' : 'greater';
  
  if (a.length === b.length) {
    for (let i = 0; i < a.length; i++) {
      const digitA = a[i];
      const digitB = b[i];
      if (digitA > digitB) {
        return flipResult ? 'less' : 'greater';
      } else if (digitA < digitB) {
        return flipResult ? 'greater' : 'less';
      }
    }
    if (aDecimal || bDecimal) {
      while (aDecimal[aDecimal.length - 1] === '0') {
        aDecimal = aDecimal.slice(0, aDecimal.length - 1);
      }
    
      while (bDecimal[bDecimal.length - 1] === '0') {
        bDecimal = bDecimal.slice(0, bDecimal.length - 1);
      }

      while (aDecimal.length < bDecimal.length) {
        aDecimal += '0';
      }

      while (bDecimal.length < aDecimal.length) {
        bDecimal += '0';
      }      
      return compare(aDecimal, bDecimal, flipResult);
    }    
    return 'equal';
    
  }
  if (a.length < b.length) return flipResult ? 'greater' : 'less';
  
}