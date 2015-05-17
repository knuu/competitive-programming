N = int(input())
desk = [list(map(int, input().split())) for _ in range(N)]
print(sum((((c-1)//2+1)*d)%(10**9+7) for c, d in desk)%(10**9+7))
