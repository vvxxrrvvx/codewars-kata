def sum_of_intervals(intervals):
    # Merge overlapping intervals
    merged = []
    for interval in sorted(intervals):
        if not merged or interval[0] > merged[-1][1]:
            merged.append(interval)
        else:
            merged[-1] = [merged[-1][0], max(merged[-1][1], interval[1])]

    # Calculate total length
    total_length = 0
    for interval in merged:
        total_length += interval[1] - interval[0]

    return total_length