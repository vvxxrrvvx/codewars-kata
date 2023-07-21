def interleave(*args):
    max_length = max(len(arg) for arg in args)
    result = []
    for i in range(max_length):
        for arg in args:
            if i < len(arg):
                result.append(arg[i])
            else:
                result.append(None)
    return result