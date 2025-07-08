## 1. 리스트 컴프리헨셔으로 열 단위 재구성
- **목적**: 매번 크레인을 내릴 때마다 보드를 탐색하지 않도록, 각 열을 한 번씩만 스캔해 stack 형태로 변환
- **해당 코드**:
```
cols = []
for j in range(len(board[0])):
    col = [board[i][j] for i in range(len(board)) if board[i][j] != 0]
    cols.append(col)
```
- **설명**:   
  `j`는 열 인덱스
  내부 리스트 컴프리헨션으로 위 -> 아래 순서대로 인형만 추출 (0 제외)
  결과를 `cols[j]`에 저장 -> 각 열이 queue처럼 앞에서 꺼낼 수 있는 구조가 됨

## 2. `bucket`을 Stack으로 사용
- **목적**: 크레인으로 뽑은 인형을 쌓고, 위에서 두 개가 같은지 즉시 판단
- **해당 코드**:
```
bucket.append(cols[m - 1].pop(0))
if len(bucket) >= 2 and bucket[-1] == bucket[-2]:
    bucket.pop()
    bucket.pop()
    answer += 2
```
- **설명**:   
  `cols[m - 1].pop(0)`은 열의 맨 위 인형 제거
  `bucket` 최상단 두 인형이 동일하면 연속 두 번 `pop` -> 사라진 인형 수를 `answer`에 2만큼 누적
