def largest_difference(data):
    max_diff = 0

    for i in range(len(data)):
        for j in range(i + 1, len(data)):
            if data[i] <= data[j] and j - i > max_diff:
                max_diff = j - i

    return max_diff