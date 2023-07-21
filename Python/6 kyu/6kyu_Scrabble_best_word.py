def get_best_word(points, words):
    highest_score = 0
    shortest_length = float('inf')
    best_index = 0

    for i, word in enumerate(words):
        word_score = sum(points[ord(c) - ord('A')] for c in word)
        word_length = len(word)

        if word_score > highest_score or (word_score == highest_score and word_length < shortest_length):
            highest_score = word_score
            shortest_length = word_length
            best_index = i

    return best_index