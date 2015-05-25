N = int(input()) 
time = sorted(map(int, input().split()))
ans = 0
tsum = 0
for t in time:
    if tsum <= t:
        ans += 1
        tsum += t
print(ans)
        
