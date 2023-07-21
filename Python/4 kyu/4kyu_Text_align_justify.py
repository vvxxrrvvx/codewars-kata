def justify(text, width):
    words = text.split()
    lines = []
    current_line = []
    current_length = 0

    for word in words:
        if current_length + len(current_line) + len(word) <= width:
            current_line.append(word)
            current_length += len(word)
        else:
            lines.append(current_line)
            current_line = [word]
            current_length = len(word)

    lines.append(current_line)

    justified_lines = []
    for i, line in enumerate(lines[:-1]):
        num_gaps = len(line) - 1
        total_spaces = width - sum(len(word) for word in line)
        if num_gaps == 0:
            justified_lines.append(' '.join(line))
        else:
            spaces_per_gap = total_spaces // num_gaps
            extra_spaces = total_spaces % num_gaps
            justified_line = ''
            for j, word in enumerate(line):
                justified_line += word
                if j < num_gaps:
                    justified_line += ' ' * (spaces_per_gap + (1 if j < extra_spaces else 0))
            justified_lines.append(justified_line)

    last_line = ' '.join(lines[-1])
    justified_lines.append(last_line)

    return '\n'.join(justified_lines)