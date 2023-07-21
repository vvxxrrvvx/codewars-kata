def splitlist(lst):
    total_sum = sum(lst)
    target_sum = total_sum // 2
    num_jobs = len(lst)

    dp = [[False] * (target_sum + 1) for _ in range(num_jobs + 1)]

    for i in range(num_jobs + 1):
        dp[i][0] = True

    for i in range(1, num_jobs + 1):
        for j in range(1, target_sum + 1):
            if j < lst[i - 1]:
                dp[i][j] = dp[i - 1][j]
            else:
                dp[i][j] = dp[i - 1][j] or dp[i - 1][j - lst[i - 1]]

    closest_sum = 0
    for j in range(target_sum, -1, -1):
        if dp[num_jobs][j]:
            closest_sum = j
            break

    a = []
    b = []
    i = num_jobs
    j = closest_sum
    while i > 0 and j > 0:
        if dp[i - 1][j]:
            i -= 1
        else:
            a.append(lst[i - 1])
            j -= lst[i - 1]
            i -= 1

    b = [job for job in lst if job not in a]

    return a, b