def combos(n):
    def backtrack(remaining, combination, start):
        if remaining == 0:
            result.append(combination[:])
            return
        for i in range(start, remaining + 1):
            combination.append(i)
            backtrack(remaining - i, combination, i)
            combination.pop()

    result = []
    backtrack(n, [], 1)
    return result