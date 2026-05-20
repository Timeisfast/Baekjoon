T = int(input())
for test_case in range(1, T + 1):
    N, k = input().split()
    k = int(k)
	
    possible = set([N])
    
    for _ in range(k):
        n_possible = set()
        
        for n in possible:
            l = list(n)
            for i in range(len(l)):
                for j in range(i + 1, len(l)):
                    l[i], l[j] = l[j], l[i]
                    n_possible.add("".join(l))
                    
                    l[i], l[j] = l[j], l[i]
        possible = n_possible
    
    ans = max(int(x) for x in possible)
    print(f"#{test_case}", ans)
    