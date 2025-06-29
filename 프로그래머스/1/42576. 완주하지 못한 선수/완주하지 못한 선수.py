def solution(participant, completion):
    hashDict = {}
    temp = 0
    
    for p in participant:
        hashDict[hash(p)] = p
        temp += hash(p)
    
    for c in completion:
        temp -= hash(c)
    
    return hashDict[temp]