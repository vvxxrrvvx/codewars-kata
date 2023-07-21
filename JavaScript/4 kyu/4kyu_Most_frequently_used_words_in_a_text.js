function topThreeWords(text) {
  const words = text.toLowerCase().match(/[a-z]+(?:'[a-z]+)?/g) || [];
  const frequencyMap = {};

  for (const word of words) {
    frequencyMap[word] = (frequencyMap[word] || 0) + 1;
  }

  return Object.entries(frequencyMap)
    .sort((a, b) => b[1] - a[1])
    .slice(0, 3)
    .map(entry => entry[0]);
}