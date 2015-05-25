N = int(input())
A = sorted(list(map(lambda x:int(x)-1, input().split())))
A = list(map(lambda x: x-A[0], A))
bucket = [0]*6010
for a in A: bucket[a] += 1
ans = 0
for i in range(6000):
    if bucket[i] > 1:
        ans += bucket[i] - 1
        bucket[i+1] += bucket[i] - 1
print(ans)
