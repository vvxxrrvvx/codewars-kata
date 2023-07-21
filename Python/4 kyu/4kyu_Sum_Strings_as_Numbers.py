def sum_strings(x, y):
    x = x[::-1]
    y = y[::-1]
    result = []
    carry = 0
    i = 0
    while i < len(x) or i < len(y):
        digit_x = int(x[i]) if i < len(x) else 0
        digit_y = int(y[i]) if i < len(y) else 0
        digit_sum = digit_x + digit_y + carry
        result.append(str(digit_sum % 10))
        carry = digit_sum // 10
        i += 1
    if carry:
        result.append(str(carry))
    result = ''.join(result[::-1])
    if result.startswith('0'):
        result = result.lstrip('0')
    return result or '0'