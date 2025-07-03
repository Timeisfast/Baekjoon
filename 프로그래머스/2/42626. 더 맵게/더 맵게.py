from heapq import *

def solution(scoville, K):
    answer = 0
    heapify(scoville)
    while scoville[0] < K and len(scoville) > 1:
        n1 = heappop(scoville)
        n2 = heappop(scoville)
        heappush(scoville, n1 + n2 * 2)
        answer += 1
    return answer if scoville[0] >= K else -1