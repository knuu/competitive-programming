N, K = map(int, input().split())
array = sorted(map(int, input().split()))
left, right = 0, 1

ans = 0
while right < N:
    val = array[right] - array[left]
    if val == K:
        ans += 1
        right += 1
        left += 1
    elif val < K:
        right += 1
    else:
        left += 1
print(ans)
