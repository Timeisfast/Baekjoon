def solution(answers):
    p1 = ([1, 2, 3, 4, 5] * 2000)[:len(answers)]
    p2 = ([2, 1, 2, 3, 2, 4, 2, 5] * 1250)[:len(answers)]
    p3 = ([3, 3, 1, 1, 2, 2, 4, 4, 5, 5] * 1000)[:len(answers)]
    
    p1_correct = sum([(x == y) for x, y in zip(p1, answers)])
    p2_correct = sum([(x == y) for x, y in zip(p2, answers)])
    p3_correct = sum([(x == y) for x, y in zip(p3, answers)])
    
    max_val = max(p1_correct, p2_correct, p3_correct)
    answer = []
    if p1_correct == max_val:
        answer.append(1)
    if p2_correct == max_val:
        answer.append(2)
    if p3_correct == max_val:
        answer.append(3)
    
    return answer