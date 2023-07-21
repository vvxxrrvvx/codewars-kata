def separate_liquids(glass):
    if not glass:
        return glass
    density_chart = {'H': 1.36, 'W': 1.00, 'A': 0.87, 'O': 0.80}
    sorted_glass = sorted([liquid for row in glass for liquid in row], key=density_chart.get)
    sorted_glass_2d = [sorted_glass[i:i+len(glass[0])] for i in range(0, len(sorted_glass), len(glass[0]))]
    return sorted_glass_2d