function treasure(maze, x, y) {
  const width = maze[0].length;
  const height = maze.length;
  
  // Check if the entrance is a treasure
  if (maze[y - 1][x - 1] !== ' ') {
    return `The treasure is ${maze[y - 1][x - 1]} :)`;
  }
  
  // Define the four directions: N, E, S, W
  const directions = [[0, -1], [1, 0], [0, 1], [-1, 0]];
  
  // Create a queue to store the coordinates to visit
  const queue = [[x - 1, y - 1]];
  
  // Create a visited set to keep track of visited coordinates
  const visited = new Set();
  
  // Perform a breadth-first search
  while (queue.length > 0) {
    const [currX, currY] = queue.shift();
    
    // Check if the current block is a treasure
    if (maze[currY][currX] !== ' ') {
      return `The treasure is ${maze[currY][currX]} :)`;
    }
    
    // Mark the current block as visited
    visited.add(`${currX},${currY}`);
    
    // Explore the adjacent blocks
    for (const [dx, dy] of directions) {
      const nextX = currX + dx;
      const nextY = currY + dy;
      
      // Check if the next block is within the maze boundaries and is not a wall or visited
      if (nextX >= 0 && nextX < width && nextY >= 0 && nextY < height &&
          maze[nextY][nextX] !== 'X' && !visited.has(`${nextX},${nextY}`)) {
        queue.push([nextX, nextY]);
      }
    }
  }
  
  // No treasure found
  return 'No treasure found :(';
}