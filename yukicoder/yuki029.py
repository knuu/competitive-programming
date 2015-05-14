N = int(input())
items =[0]*10
for i in range(N):
    a, b, c = map(lambda x:int(x)-1, input().split())
    items[a] += 1
    items[b] += 1
    items[c] += 1
ans = 0
for i in range(10):
    ans += items[i]//2
    items[i] %= 2
ans += sum(items) // 4
print(ans)
