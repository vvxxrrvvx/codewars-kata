def fib_digits(n):
    fib = [0, 1]  # Initialize Fibonacci sequence
    digit_counts = [0] * 10  # Initialize digit counts

    for i in range(2, n + 1):
        fib.append(fib[i - 1] + fib[i - 2])  # Generate Fibonacci number

    # Count the occurrence of each digit in the Fibonacci number
    for digit in str(fib[n]):
        digit_counts[int(digit)] += 1

    # Create a list of integer pairs [(count, digit)] excluding digits with zero count
    pairs = [(count, digit) for digit, count in enumerate(digit_counts) if count > 0]

    # Sort the list in descending order based on count, then digit
    pairs.sort(key=lambda x: (-x[0], -x[1]))

    return pairs