def solution(ingredient):
    stack = []
    pattern = [1, 2, 3, 1]
    answer = 0
    for x in ingredient:
        stack.append(x)
        if len(stack) >= 4 and stack[-4:] == pattern:
            del stack[-4:]
            answer += 1
    return answer