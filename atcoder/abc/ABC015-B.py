x = int(input())
l = list(map(int, input().strip().split()))
c = l.count(0)


if sum(l) % (x-c) == 0:
    print(int(sum(l)/(x-c)))
else:
    print(int(sum(l)/(x-c) + 1))
