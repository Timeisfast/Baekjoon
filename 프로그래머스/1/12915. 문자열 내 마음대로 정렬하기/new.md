## 1. sort() vs sorted()
```
nums = [3, 1, 2]
nums.sort()
sorted_nums = sorted(nums)
```
|  | sort() | sorted() |
| ----- | ------------------- | ------------------- |
| 반환값 | None | 정렬된 새 리스트 |
| in-place | O | X |

## 2. lambda를 통한 정렬
익명 함수를 `key` 인자에 전달해서 정렬 기준 설정
```
words = ['banana', 'apple', 'cherry']
sorted(words, key=lambda x: len(x))  # 문자열 길이 기준 정렬
# 결과: ['apple', 'banana', 'cherry']
```

## 3. 다중 조건 정렬
`key=lambda x: (조건1, 조건2, ...)` 형태로 여러 기준 정렬
```
data = [(1, 2), (3, 1), (1, 3), (2, 2)]
sorted(data, key=lambda x: (x[0], -x[1]))
# 결과: [(1, 3), (1, 2), (2, 2), (3, 1)]
```
