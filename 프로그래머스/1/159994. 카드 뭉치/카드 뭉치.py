def solution(cards1, cards2, goal):
    flag = True
    for word in goal:
        if cards1 and cards1[0] == word:
            del cards1[0]
        elif cards2 and cards2[0] == word:
            del cards2[0]
        else:
            flag = False
            break
    return "Yes" if flag else "No"