def cheapest_path(t, start, finish):
    rows, cols = len(t), len(t[0])
    
    # initialize cost and direction matrices
    cost = [[float('inf') for j in range(cols)] for i in range(rows)]
    direction = [[None for j in range(cols)] for i in range(rows)]
    
    # set start position cost to 0
    i, j = start
    cost[i][j] = 0
    
    # initialize priority queue with start position
    queue = [(i, j)]
    
    # define directions and their corresponding position offsets
    directions = ["up", "right", "down", "left"]
    offsets = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    
    # loop until queue is empty or finish position is reached
    while queue:
        i, j = queue.pop(0)
        
        # check all directions
        for k in range(len(directions)):
            # calculate new position
            i2, j2 = i + offsets[k][0], j + offsets[k][1]
            
            # check if new position is within bounds
            if i2 >= 0 and i2 < rows and j2 >= 0 and j2 < cols:
                # calculate new cost
                new_cost = cost[i][j] + t[i2][j2]
                
                # update cost and direction matrices if new cost is lower
                if new_cost < cost[i2][j2]:
                    cost[i2][j2] = new_cost
                    direction[i2][j2] = directions[k]
                    
                    # add new position to queue
                    queue.append((i2, j2))
    
    # backtrack from finish position to start position using direction matrix
    i, j = finish
    path = []
    while direction[i][j]:
        path.append(direction[i][j])
        k = directions.index(direction[i][j])
        i, j = i - offsets[k][0], j - offsets[k][1]
    return path[::-1]