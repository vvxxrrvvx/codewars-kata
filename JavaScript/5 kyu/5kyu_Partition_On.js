function partitionOn(pred, items) {
  var trueValues = items.filter(pred);
  var falseValues = items.filter(function(item) {
    return !pred(item);
  });

  Array.prototype.splice.apply(items, [0, items.length].concat(falseValues.concat(trueValues)));
  return falseValues.length;
}