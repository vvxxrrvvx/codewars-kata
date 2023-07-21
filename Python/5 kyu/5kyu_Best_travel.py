def choose_best_sum(t, k, ls):
    if len(ls) < k:
        return None

    max_sum = -1

    def find_combinations(index, count, curr_sum):
        nonlocal max_sum

        if count == k:
            if curr_sum <= t and curr_sum > max_sum:
                max_sum = curr_sum
            return

        if index >= len(ls):
            return

        find_combinations(index + 1, count + 1, curr_sum + ls[index])
        find_combinations(index + 1, count, curr_sum)

    find_combinations(0, 0, 0)

    if max_sum == -1:
        return None
    else:
        return max_sum