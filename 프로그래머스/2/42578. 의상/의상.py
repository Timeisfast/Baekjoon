from collections import Counter

def solution(clothes):
    category = [x[1] for x in clothes]
    category_count = Counter(category)
    
    answer = 1
    for value in category_count.values():
        answer *= value + 1
    
    return answer - 1