import numpy as np
from itertools import dropwhile

def solution(board, moves):
    board = np.array(board).T.tolist()
    board = [list(dropwhile(lambda x: x == 0, row)) for row in board]
    
    bucket = []
    answer = 0
    for m in moves:
        if len(board[m - 1]) != 0:
            bucket.append(board[m - 1].pop(0))
            if len(bucket) > 1 and bucket[-1] == bucket[-2]:
                bucket.pop(-1)
                bucket.pop(-1)
                answer += 2
    return answer