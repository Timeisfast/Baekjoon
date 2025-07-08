def solution(s):
    d = {}
    answer = []
    for i, c in enumerate(s):
        answer.append(-1 if c not in d else (i - d[c]))
        d[c] = i
    return answer