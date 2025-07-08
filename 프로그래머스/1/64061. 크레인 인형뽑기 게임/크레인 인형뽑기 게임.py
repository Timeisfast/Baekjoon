def solution(board, moves):
    cols = []
    for j in range(len(board[0])):
        col = [board[i][j] for i in range(len(board)) if board[i][j] != 0]
        cols.append(col)
    
    bucket = []
    answer = 0
    for m in moves:
        if cols[m - 1]:
            bucket.append(cols[m - 1].pop(0))
            if len(bucket) >= 2 and bucket[-1] == bucket[-2]:
                bucket.pop()
                bucket.pop()
                answer += 2
    return answer