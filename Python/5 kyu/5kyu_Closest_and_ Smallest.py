def closest(strng):
    if not strng:
        return []

    numbers = strng.split()
    weights = []
    for num in numbers:
        weight = sum(int(digit) for digit in num)
        weights.append(weight)

    min_diff = float('inf')
    pairs = []
    for i in range(len(weights)):
        for j in range(i + 1, len(weights)):
            diff = abs(weights[i] - weights[j])
            if diff < min_diff:
                min_diff = diff
                pairs = [[weights[i], i, int(numbers[i])], [weights[j], j, int(numbers[j])]]
            elif diff == min_diff:
                if weights[i] < pairs[0][0] or (weights[i] == pairs[0][0] and i < pairs[0][1]):
                    pairs = [[weights[i], i, int(numbers[i])], [weights[j], j, int(numbers[j])]]
                elif weights[j] < pairs[0][0] or (weights[j] == pairs[0][0] and j < pairs[0][1]):
                    pairs = [[weights[i], i, int(numbers[i])], [weights[j], j, int(numbers[j])]]

    return sorted(pairs, key=lambda x: (x[0], x[1]))