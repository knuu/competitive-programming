n = int(input())
m = [int(input()) for _ in range(3)]
cnt = int(n / sum(m)) * 3
n %= sum(m)
m.sort()
if n == 0:
    print(cnt)
elif n <= m[2]:
    print(cnt+1)
elif n <= m[1] + m[2]:
    print(cnt+2)
else:
    print(cnt+3)
