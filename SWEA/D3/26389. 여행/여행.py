T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    A = input()
    flag = True
    if ('N' in A) ^ ('S' in A):
        flag = False
    if ('E' in A) ^ ('W' in A):
        flag = False
    
    print("Yes" if flag else "No")