n, k = map(int, input().split())
t = [int(input()) for _ in range(n)]
s = [sum(t[i:i+3]) for i in range(n-3)]
for i in range(len(s)):
    if s[i] < k:
        print(i+3)
        quit()
print(-1)
