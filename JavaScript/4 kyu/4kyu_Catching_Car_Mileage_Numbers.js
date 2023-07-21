const chars = n => n.toString().split("");
const match = s => n => new RegExp(n).test(s);

const tests = [
  match("1234567890"), 
  match("9876543210"), 
  n => /^\d[0]+$/.test(n),
  n =>
    n ==
    chars(n)
      .reverse()
      .join(""), 
  n => [...new Set(chars(n))].length === 1 
];

const test = (n, xs) =>
  n > 99 && (xs.indexOf(n) > -1 || tests.map(t => t(n)).some(x => !!x));

const isInteresting = (n, xs) =>
  test(n, xs) ? 2 : +(test(n + 1, xs) || test(n + 2, xs));