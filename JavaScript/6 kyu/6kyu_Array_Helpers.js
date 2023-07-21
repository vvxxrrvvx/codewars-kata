Array.prototype.square = function() {
  const squared = [];
  for (let i = 0; i < this.length; i++) {
    const element = this[i];
    const result = element**2;
    squared.push(result);
  }
  return squared;
};

Array.prototype.square = function() {
  return this.map(element => element ** 2);
};

Array.prototype.cube = function() {
  return this.map(element => element ** 3);
};

Array.prototype.sum = function() {
  let result = 0;
  for (let i = 0; i < this.length; i++) {
    const element = this[i];
    result += element;
  }
  return result;
};

Array.prototype.sum = function() {
  let result = 0;
  this.forEach(element => {
    result += element;
  });
  return result;
};

Array.prototype.sum = function() {
  return this.reduce((result, element) => {
    result += element;
    return result;
  }, 0);
};

Array.prototype.sum = function() {
  return this
    .reduce((result, element) => result + element, 0);
};

Array.prototype.average = function() {
  return this.sum() / this.length;
};

Array.prototype.even = function() {
  const evens = [];
  for (let i = 0; i < this.length; i++) {
    const element = this[i];
    if (element % 2 === 0) {
      evens.push(element);
    }
  }
  return evens;
};

Array.prototype.even = function() {
  return this
    .filter(element => element%2 === 0);
};

Array.prototype.odd = function() {
  return this
    .filter(element => element%2 !== 0);
};

Array.prototype.odd = function() {
  return this
    .filter(element => element%2);
};