K, T = map(int, input().split())
A = max(map(int, input().split()))
if A <= K // 2 + K % 2:
    print(0)
elif T == 1:
    print(K-1)
elif K % 2 == 0:
    print((A - K // 2) * 2 - 1)
else:
    print((A - K // 2 + 1) * 2)
