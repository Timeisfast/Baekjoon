def solution(players, callings):
    rank = {p: i for i, p in enumerate(players)}
    for name in callings:
        idx = rank[name]
        rank[name] -= 1
        rank[players[idx - 1]] += 1
        players[idx - 1], players[idx] = players[idx], players[idx - 1]
    return players