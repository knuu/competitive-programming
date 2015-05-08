L = int(input())
N = int(input())
W = list(map(int, input().split()))
W.sort()
ans = 0
s = 0
while ans < N and W[ans] + s <= L:
    s += W[ans]
    ans += 1
print(ans)
