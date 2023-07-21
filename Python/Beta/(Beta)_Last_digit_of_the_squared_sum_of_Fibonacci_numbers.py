def fibonacci_squared_sum(n):
    def fibonacci_last_digit(n):
        fib = [0, 1]
        for i in range(2, n + 1):
            fib.append((fib[i - 1] + fib[i - 2]) % 10)
        return fib[n]
    last_digit_fib_n = fibonacci_last_digit(n % 60)
    sum_squares = last_digit_fib_n * (last_digit_fib_n + fibonacci_last_digit((n - 1) % 60))
    return sum_squares % 10