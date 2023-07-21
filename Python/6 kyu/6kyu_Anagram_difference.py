def anagram_difference(w1, w2):
    w1 = "".join(w1)
    w2 = "".join(w2)
    w1 = w1.lower()
    w2 = w2.lower()    
    def get_char_count(word):
        char_count = {}
        for char in word:
            char_count[char] = char_count.get(char, 0) + 1
        return char_count
    w1_char_count = get_char_count(w1)
    w2_char_count = get_char_count(w2)
    total_chars_to_remove = 0
    for char, count in w1_char_count.items():
        total_chars_to_remove += abs(count - w2_char_count.get(char, 0))    
    for char, count in w2_char_count.items():
        if char not in w1_char_count:
            total_chars_to_remove += count
    return total_chars_to_remove