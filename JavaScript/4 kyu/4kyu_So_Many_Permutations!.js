function permutations(string) {
  const set = new Set();

  function permute(str, prefix = '') {
    if (str.length === 0) {
      set.add(prefix);
    } else {
      for (let i = 0; i < str.length; i++) {
        permute(str.slice(0, i) + str.slice(i + 1), prefix + str[i]);
      }
    }
  }

  permute(string);
  return [...set];
}