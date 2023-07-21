function breakApart(number) {
  let [integer] = number.toString().split('.').map(Number);
  const decimal = number - integer;
  return {
    integer,
    decimal
  };
}

Math.round = function(number) {
  const { integer, decimal } = breakApart(number);
  return integer + (decimal >= .5 ? 1 : 0);  
};

Math.ceil = function(number) {
  const { integer, decimal } = breakApart(number);
  return decimal > 0 ? integer + 1 : integer;  
};

Math.floor = function(number) {
  const { integer } = breakApart(number);
  return integer;
};