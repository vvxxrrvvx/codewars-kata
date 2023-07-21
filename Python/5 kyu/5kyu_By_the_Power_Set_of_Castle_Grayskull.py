def power(a):
    n = len(a)
    power_set = []
    for i in range(2**n):  
        subset = []
        for j in range(n):
            if (i >> j) & 1:  
                subset.append(a[j])
        power_set.append(subset)
    return power_set