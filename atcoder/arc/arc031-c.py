def add(update, value):
    x = update
    while x < n:
        bit[x] += value
        x |= x + 1

def sum(update):
    ret = 0
    x = update
    while x >= 0:
        ret += bit[x]
        x = (x & (x + 1)) - 1
    return ret

n = int(input())
b = list(map(int, input().split()))
s = [(x, cnt) for cnt, x in enumerate(b)]
s.sort()
bit = [(x+1) & -(x+1) for x in range(n+10)]

ans = 0
for i, cnt in s:
    add(cnt, -1)
    ans += min(sum(cnt), sum(len(b) - 1) - sum(cnt))

print(ans)
