n = int(input())
a = sorted(list(map(int, input().split())), reverse=True)
a_sum = sum(a)

your_mon = 0
for i in range(n):
    your_mon += a[i]
    if your_mon > a_sum // 2:
        print(i+1)
        exit(0)
