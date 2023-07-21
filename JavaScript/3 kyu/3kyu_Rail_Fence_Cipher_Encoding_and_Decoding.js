function encodeRailFenceCipher(string, numberRails) {
  if (numberRails < 2) {
    return string;
  }

  const rails = new Array(numberRails).fill('');
  let currentRail = 0;
  let goingDown = true;

  for (let i = 0; i < string.length; i++) {
    rails[currentRail] += string[i];

    if (goingDown) {
      currentRail++;
    } else {
      currentRail--;
    }

    if (currentRail === 0 || currentRail === numberRails - 1) {
      goingDown = !goingDown;
    }
  }

  return rails.join('');
}

function decodeRailFenceCipher(string, numberRails) {
  if (numberRails < 2) {
    return string;
  }

  const rails = new Array(numberRails).fill('');
  const railLengths = new Array(numberRails).fill(0);
  let currentRail = 0;
  let goingDown = true;

  for (let i = 0; i < string.length; i++) {
    railLengths[currentRail]++;

    if (goingDown) {
      currentRail++;
    } else {
      currentRail--;
    }

    if (currentRail === 0 || currentRail === numberRails - 1) {
      goingDown = !goingDown;
    }
  }

  let railIndex = 0;
  for (let i = 0; i < numberRails; i++) {
    for (let j = 0; j < railLengths[i]; j++) {
      rails[i] += string[railIndex++];
    }
  }

  currentRail = 0;
  goingDown = true;
  let result = '';

  for (let i = 0; i < string.length; i++) {
    result += rails[currentRail][0];
    rails[currentRail] = rails[currentRail].substr(1);

    if (goingDown) {
      currentRail++;
    } else {
      currentRail--;
    }

    if (currentRail === 0 || currentRail === numberRails - 1) {
      goingDown = !goingDown;
    }
  }

  return result;
}