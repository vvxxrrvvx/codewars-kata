import math

def nearest_fibonacci(number):
    # Base case for Fibonacci sequence
    if number <= 0:
        return 0

    # Initialize Fibonacci numbers
    fib_prev = 0
    fib_current = 1

    # Find the nearest Fibonacci number
    while fib_current <= number:
        fib_prev, fib_current = fib_current, fib_prev + fib_current

    # Compare the distance to the previous and current Fibonacci numbers
    diff_prev = number - fib_prev
    diff_current = fib_current - number

    if diff_prev <= diff_current:
        return fib_prev
    else:
        return fib_current
