## 1. map(function, iterable)
- **목적**: 반복 가능한 객체의 각 요소에 함수를 적용
- **예시**:
```
numbers = [3, 30, 34]
numbers_str = list(map(str, numbers))
```
- **설명**:   
  각 정수를 문자열로 바꿔 리스트로 만듦   
  map의 반환값은 iterator

## 2. functools.cmp_to_key(cmp_function)
- **목적**: 비교 함수(cmp)를 key 함수로 변환
- **사용 이유**: Python3에서는 sorted()나 sort()에 직접 cmp를 넘길 수 없기 때문
- **예시**:
```
from functools import cmp_to_key
numbers_str.sort(key=cmp_to_key(comparator), reverse=True)
```
- **비교 함수**:   
str로 주어진 a, b에서 a + b와 b + a 중 어떤 조합이 더 큰 수를 만드는지 비교
```
def comparator(a, b):
  t1 = a + b
  t2 = b + a
  return (int(t1) > int(t2)) - (int(t1) < int(t2))
```

## 3. '구분자'.join(iterable)
- **목적**: 리스트, 튜플, 문자열 등 반복 가능한(iterable) 객체의 요소들을 하나의 문자열로 합칠 때 사용
- 각 요소 사이에 구분자를 넣어서 연결
- **제한 조건**: iterable 내부의 요소는 모두 문자열이어야 함
- **예시**:
```
lst = ['a', 'b', 'c']
''.join(lst)  # 'abc'
', '.join(lst) # 'a, b, c'
'\n'.join(lst)
# a
# b
# c
```

### tip
해당 문제의 마지막에 사용된 `str(int(...))`은 주어진 리스트가 `[0, 0, 0]`인 경우 `"000"`이 되는 것을 방지한다.
