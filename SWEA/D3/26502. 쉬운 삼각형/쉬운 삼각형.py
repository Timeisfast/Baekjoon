from collections import defaultdict

T = int(input())
for test_case in range(1, T + 1):
    N = int(input())
    points = []
    pos_x = defaultdict(list)
    pos_y = defaultdict(list)
    
    for _ in range(N):
        x, y = map(int, input().split())
        points.append((x, y))
        pos_x[x].append(y)
        pos_y[y].append(x)
    
    ans = 0
    for x, y in points:
        if len(pos_x[x]) > 1:
            h = max(max(pos_x[x]) - y, y - min(pos_x[x]))
        else:
            continue
        
        if len(pos_y[y]) > 1:
            w = max(max(pos_y[y]) - x, x - min(pos_y[y]))
        else:
            continue
        
        ans = max(ans, w * h)
    print(ans)