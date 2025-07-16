import heapq

def solution(operations):
    max_heap = []
    min_heap = []
    removed_min = {}
    removed_max = {}
    
    for op in operations:
        if op[0] == 'I':
            n = int(op[2:])
            heapq.heappush(max_heap, -n)
            heapq.heappush(min_heap, n)
        elif op[0] == 'D':
            if op[2:] == '1':
                while max_heap and removed_min.get(-max_heap[0], 0) > 0:
                    removed = -heapq.heappop(max_heap)
                    removed_min[removed] -= 1
                if max_heap:
                    n = -heapq.heappop(max_heap)
                    removed_max[n] = removed_max.get(n, 0) + 1
            elif op[2:] == '-1':
                while min_heap and removed_max.get(min_heap[0], 0) > 0:
                    removed = heapq.heappop(min_heap)
                    removed_max[removed] -= 1
                if min_heap:
                    n = heapq.heappop(min_heap)
                    removed_min[n] = removed_min.get(n, 0) + 1
                    
    while max_heap and removed_min.get(-max_heap[0], 0) > 0:
        removed = -heapq.heappop(max_heap)
        removed_min[removed] -= 1
        
    while min_heap and removed_max.get(min_heap[0], 0) > 0:
        removed = heapq.heappop(min_heap)
        removed_max[removed] -= 1
    
    if not max_heap or not min_heap:
        answer = [0, 0]
    else:
        answer = [-max_heap[0], min_heap[0]]
    return answer