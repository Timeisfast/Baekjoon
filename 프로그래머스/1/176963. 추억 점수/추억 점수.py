from collections import Counter

def solution(name, yearning, photo):
    cnts = [Counter(p) for p in photo]
    answer = []
    for c in cnts:
        s = sum([c[n] * y for n, y in zip(name, yearning)])
        answer.append(s)
    return answer