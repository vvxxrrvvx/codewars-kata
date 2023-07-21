def frogs_jumping(stones):
    paths = {0: ""}
    
    for stone in stones:
        if stone not in paths:
            continue
        
        path = paths[stone]
        short_jump = stone + 1
        long_jump = stone + 2
        
        if short_jump not in paths or len(paths[short_jump]) > len(path) + 1:
            paths[short_jump] = path + "1"
            
        if long_jump not in paths or len(paths[long_jump]) > len(path) + 1:
            paths[long_jump] = path + "2"
    
    return paths[stones[-1]]