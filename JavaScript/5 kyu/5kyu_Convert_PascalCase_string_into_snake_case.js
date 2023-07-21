function toUnderscore(string) {
  if (typeof string !== 'string') return string.toString();  
  const words = string.match(/[A-Z0-9][a-z0-9]*/g);
  console.log(words);
  const lowerCaseWords = words.map(word => word.toLowerCase());
  console.log(lowerCaseWords);  
  return lowerCaseWords.join('_');
}

function toUnderscore(string) {
  if (typeof string !== 'string') return string.toString();
  return string
    .match(/[A-Z0-9][a-z0-9]*/g)
    .map(word => word.toLowerCase())
    .join('_');
}

function toUnderscore(string) {
  if (typeof string !== 'string') return string.toString();
  return string.replace(/[A-Z]/g, (letter) => '_' + letter.toLowerCase()).slice(1);
}

function toUnderscore(string) {
  if (typeof string !== 'string') return string.toString();
  return string.replace(/([A-Z])/g, '_$1').toLowerCase().slice(1);
}