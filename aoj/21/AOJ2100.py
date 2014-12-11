d = int(input())
for i in range(d):
    n = int(input())
    l = list(map(int, input().split()))
    dis = [l[i+1] - l[i] for i in range(n - 1)]
    M, m = max(dis), min(dis)
    if M > 0 and m > 0:
        print(M, 0)
    elif M < 0 and m < 0:
        print(0, abs(m))
    else:
        print(M, abs(m))
