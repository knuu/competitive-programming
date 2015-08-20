N = int(input())
A = [int(x)-1 for x in input().split()]
ans = 0
left = 0
bucket = [0] * (10**5)
for right in range(N):
    bucket[A[right]] += 1
    while bucket[A[right]] > 1:
        bucket[A[left]] -= 1
        left += 1
    ans = max(ans, right - left + 1)
print(ans)
