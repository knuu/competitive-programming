from collections import deque

N = int(input())
A = [int(input()) for _ in range(N)]

A.sort()

deq = deque()
for a in A:
    deq.append(a)

ans1 = 0
left = right = deq.pop()
flag = 1
while len(deq) >= 2:
    if flag:
        l, r = deq.popleft(), deq.popleft()
    else:
        l, r = deq.pop(), deq.pop()
    ans1 += abs(left + right - l - r)
    flag ^= 1
    left, right = l, r
if len(deq):
    v = deq.pop()
    ans1 += max(abs(left - v), abs(right - v))

deq = deque()
for a in A:
    deq.append(a)

ans2 = 0
left = right = deq.popleft()
flag = False
while len(deq) >= 2:
    if flag:
        l, r = deq.popleft(), deq.popleft()
    else:
        l, r = deq.pop(), deq.pop()
    flag ^= 1
    ans2 += abs(left + right - l - r)
    left, right = l, r
if len(deq):
    v = deq.pop()
    ans2 += max(abs(left - v), abs(right - v))

print(max(ans1, ans2))
