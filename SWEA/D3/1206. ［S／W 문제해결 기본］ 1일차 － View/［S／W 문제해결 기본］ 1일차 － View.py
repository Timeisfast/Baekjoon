for test_case in range(1, 11):
    N = int(input())
    heights = [int(x) for x in input().split()]
    
    ans = 0
    for i in range(2, N - 2):
        tmp_h = max(max(heights[i - 2 : i]), max(heights[i + 1 : i + 3]))
        if heights[i] > tmp_h:
            ans += heights[i] - tmp_h
    
    print(f"#{test_case}", ans)