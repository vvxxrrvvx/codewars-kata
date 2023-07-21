import math

def listPosition(word):
    freq = {}
    for letter in word:
        freq[letter] = freq.get(letter, 0) + 1
    unique_letters = sorted(list(set(word)))
    rank = 1

    for i, letter in enumerate(word):
        remaining_letters = word[i+1:]
        for unique_letter in unique_letters:
            if unique_letter < letter:
                if freq[unique_letter] > 0:
                    freq[unique_letter] -= 1
                    num_permutations = math.factorial(len(remaining_letters))
                    for _, value in freq.items():
                        if value > 1:
                            num_permutations //= math.factorial(value)
                    rank += num_permutations
                    freq[unique_letter] += 1

        freq[letter] -= 1

    return rank