N = int(input())

div = []
i = 1
while i * i <= N:
    if N % i == 0:
        div.append(i)
    if N // i != i:
        div.append(N // i)
    i += 1
div.sort()
prev = 0
ans = 0
for d in div:
    m = N // d - 1
    if m > 0 and N // m == N % m:
        ans += m

print(ans)
