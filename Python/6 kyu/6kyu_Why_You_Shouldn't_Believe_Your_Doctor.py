import random

def simulate(disease_rate, false_positive_rate, n):
    sick_people = [i for i in range(1, n+1) if random.random() < disease_rate]
    positive_tests = sum(1 for _ in sick_people) + sum(1 for _ in range(n - len(sick_people)) if random.random() < false_positive_rate)
    return sick_people, positive_tests