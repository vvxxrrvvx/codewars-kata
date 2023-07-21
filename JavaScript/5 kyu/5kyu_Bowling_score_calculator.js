function bowlingScore(rolls) {
  let totalScore = 0;
  
  let totalFramesScored = 0;
  
  let currentRoll = 0;

  while (currentRoll < rolls.length && totalFramesScored < 10) {
    if (rolls[currentRoll] != 10) {
      const pins = rolls[currentRoll] + rolls[currentRoll + 1];
      if (pins !== 10) {
        totalScore += pins;
      } else {
        totalScore += 10 + rolls[currentRoll + 2];
      }
      currentRoll += 2;
    } else {
      totalScore += (10 + rolls[currentRoll + 1] + rolls[currentRoll + 2]);
      currentRoll += 1;
    }
    
    totalFramesScored++;   
  }

  return totalScore;
}