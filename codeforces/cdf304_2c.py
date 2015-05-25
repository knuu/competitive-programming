from collections import deque
from copy import deepcopy
n = int(input())
A = deque(list(map(int, input().split()))[1:])
B = deque(list(map(int, input().split()))[1:])
state = []
state.append((deepcopy(A), deepcopy(B)))
cnt = 0
while len(A) > 0 and len(B) > 0:
    if A[0] > B[0]:
        A.append(B.popleft())
        A.append(A.popleft())
    else:
        B.append(A.popleft())
        B.append(B.popleft())
    if (A, B) in state:
        print(-1)
        break
    state.append((deepcopy(A), deepcopy(B)))
    cnt += 1
else:
    print(cnt, 1 if len(B) == 0 else 2)
