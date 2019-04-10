def bi_search(f, x):
    left, right = 0, 10 ** 9
    while left + 1 < right:
        mid = (left + right) // 2
        if f(mid) >= x:
            right = mid
        else:
            left = mid
    return right

N, T, K, D = map(int, input().split())

if bi_search(lambda x: x // T * K, N) > bi_search(lambda x: x // T * K + max(0, (x - D) // T * K), N):
    print("YES")
else:
    print("NO")
