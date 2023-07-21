function isTriangleNumber(number) {
  return Number.isInteger(number) && number >= 0 && Number.isInteger(Math.sqrt(8 * number + 1));
}