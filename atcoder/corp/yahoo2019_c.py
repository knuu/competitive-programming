K, A, B = map(int, input().split())
if B - A <= 2:
    print(1 + K)
elif K <= A:
    print(1 + K)
else:
    change_num = (K - (A - 1)) // 2
    print(change_num * B - (change_num - 1) * A + (K - (A - 1)) % 2)
