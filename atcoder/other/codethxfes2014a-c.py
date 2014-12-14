n, m = map(int, input().split())
p = list(map(int, input().split()))
s = list(map(int, input().split()))

ans = [p[x-1] for x in s]
print(sum(ans))
