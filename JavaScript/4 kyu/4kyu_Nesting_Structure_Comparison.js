Array.prototype.sameStructureAs = function (other) {
  if (!Array.isArray(other) || this.length !== other.length) return false;
  return this.every((el, i) => Array.isArray(el) ? el.sameStructureAs(other[i]) : !Array.isArray(other[i]));
};