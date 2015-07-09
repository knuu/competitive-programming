def check(time):
    box = A[:]
    now = last
    for student in range(m):
        rest = time - now - 1
        if rest <= 0:
            return False
        while now >= 0 and rest >= 0:
            if box[now] <= rest:
                rest -= box[now]
                now -= 1
            else:
                box[now] -= rest
                break
        if now == -1:
            return True
    return False

n, m = map(int, input().split())
A = list(map(int, input().split()))
last = n-1
while A[last] == 0:
    last -= 1

low, high = 1, n + sum(A) + 1
while high - low > 1:
    mid = (high + low) // 2
    if check(mid) == False:
        low = mid
    else:
        high = mid
print(high)
