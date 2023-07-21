function solution(input, markers) {
  return input
    .split('\n')
    .map(line => {
      markers.forEach(marker => {
        const index = line.indexOf(marker);
        if (index !== -1) {
          line = line.slice(0, index).trim();
        }
      });
      return line;
    })
    .join('\n');
}