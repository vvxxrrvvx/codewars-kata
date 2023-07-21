def beeramid(bonus, price):
    cans = bonus // price  
    level = 0  
    while cans >= (level + 1) ** 2:  
        level += 1
        cans -= level ** 2
    return level