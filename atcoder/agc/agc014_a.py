A, B, C = map(int, input().split())

for i in range(10 ** 5):
    if A % 2 or B % 2 or C % 2:
        print(i)
        break
    A, B, C = B // 2 + C // 2, C // 2 + A // 2, A // 2 + B // 2
else:
    print(-1)
