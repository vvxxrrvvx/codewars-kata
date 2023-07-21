var compose = function(value, ...functions) {
  if (functions.length === 0) {
    return value;
  }
  
  var result = value;
  for (var i = 0; i < functions.length; i++) {
    result = functions[i](result);
  }
  
  return result;
};