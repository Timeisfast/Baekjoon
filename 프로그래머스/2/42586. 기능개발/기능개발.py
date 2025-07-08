import math

def solution(progresses, speeds):
    k = 0
    answer = []
    for p, s in zip(progresses, speeds):
        if len(answer) == 0 or p + s * k < 100:
            answer.append(1)
            k = math.ceil((100 - p) / s)
        else:
            answer[-1] += 1
    return answer