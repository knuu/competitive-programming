N, M = map(int, input().split())
C = sorted(list(map(int, input().split())))
s = 0
for cnt, c in enumerate(C):
    s += c
    if M < s:
        print(cnt)
        exit(0)
print(N)
    
