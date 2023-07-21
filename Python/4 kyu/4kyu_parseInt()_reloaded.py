def parse_int(string):
    words = string.replace('-', ' ').split() # replace hyphens with spaces and split into words
    num_dict = {'zero': 0, 'one': 1, 'two': 2, 'three': 3, 'four': 4, 'five': 5, 'six': 6, 'seven': 7, 'eight': 8, 'nine': 9,
                'ten': 10, 'eleven': 11, 'twelve': 12, 'thirteen': 13, 'fourteen': 14, 'fifteen': 15, 'sixteen': 16,
                'seventeen': 17, 'eighteen': 18, 'nineteen': 19, 'twenty': 20, 'thirty': 30, 'forty': 40, 'fifty': 50,
                'sixty': 60, 'seventy': 70, 'eighty': 80, 'ninety': 90, 'hundred': 100, 'thousand': 1000, 'million': 1000000}

    total = 0
    sub_total = 0 # keeps track of values less than 1000
    for word in words:
        if word == 'and':
            continue
        val = num_dict[word]
        if val == 0 and (sub_total == 0 or sub_total >= 1000): # prevent "zero" from being added to sub_total after first number
            sub_total = 0
        elif val < 100:
            sub_total += val
        elif val < 1000:
            sub_total *= val
        else:
            total += sub_total * val
            sub_total = 0
        if sub_total >= 1000:
            total += sub_total
            sub_total = 0
    total += sub_total
    return total