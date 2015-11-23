L, H = map(int, input().split())
for _ in range(int(input())):
    a = int(input())
    if a < L:
        print(L - a)
    elif a > H:
        print(-1)
    else:
        print(0)
