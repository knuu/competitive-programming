T = int(input())

for _ in range(T):
    N, C = map(int, input().split())
    if 2 * C % N != 0:
        print("No")
        continue
    K = 2 * C // N
    if (K % 2 == 0 and (N - 1) % 2 == 0) or (K % 2 == 1 and (N - 1) % 2 == 1):
        a0 = K - (N - 1)
        assert(a0 % 2 == 0)
        print("Yes" if a0 > 0 else "No")
    elif K % 2 == 0 and (N - 1) % 2 == 1:
        a0 = K - (N - 1) * 2
        assert(a0 % 2 == 0)
        print("Yes" if a0 > 0 else "No")
    else:
        print("No")
