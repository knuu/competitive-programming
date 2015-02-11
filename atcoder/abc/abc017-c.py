n, m = map(int, input().split())
ruins = [list(map(int, input().split())) for _ in range(n)]

imos = [0] * (m+1)
sum_s = 0
for i in range(n):
    l, r, s = ruins[i]
    l -= 1
    imos[l] += s
    imos[r] -= s
    sum_s += s

for i in range(m):
    imos[i+1] += imos[i]
    
print(sum_s - min(imos[:-1]))
    
