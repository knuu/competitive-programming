n = int(input())
height = list(map(int, input().split()))
check = {}
for h in height:
    if check.get(h, 0) > 0:
        print(-1)
        quit()
    else:
        check[h] = 1


s = [(h, cnt) for cnt, h in enumerate(height)]
s.sort()

bit = [(x+1) & -(x+1) for x in range(n+10)]
def init():
    x = 0
    while x < N - 1:
        bit[x | (x + 1)] += bit[x]
        x += 1

def add(update, value):
    x = update
    while x < n:
        bit[x] += value
        x |= x + 1

def sum(update):
    ret = 0
    x = update - 1
    while x >= 0:
        ret += bit[x]
        x = (x & (x + 1)) - 1
    return ret

ans = 0
for h, cnt in s:
    add(cnt, -1)
    ans += sum(cnt) * h
print(ans)

    
