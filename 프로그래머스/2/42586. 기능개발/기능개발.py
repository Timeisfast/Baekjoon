import heapq
import math

def solution(progresses, speeds):
    k = 0
    cnt = 0
    answer = []
    for i, p in enumerate(progresses):
        if p + speeds[i] * k >= 100:
            cnt += 1
            continue
        if cnt != 0:
            answer.append(cnt)
        k = math.ceil((100 - p) / speeds[i])
        cnt = 1
    answer.append(cnt)
    return answer