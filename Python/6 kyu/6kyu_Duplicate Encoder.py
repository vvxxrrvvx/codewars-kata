def duplicate_encode(word):
    word = word.lower()
    count = {}
    encoded = ""

    for char in word:
        if char in count:
            count[char] += 1
        else:
            count[char] = 1

    for char in word:
        if count[char] > 1:
            encoded += ")"
        else:
            encoded += "("

    return encoded

