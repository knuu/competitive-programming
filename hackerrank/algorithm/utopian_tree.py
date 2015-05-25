T = int(input())
for _ in range(T):
    h = 1
    for i in range(int(input())):
        if i % 2 == 0:
            h *= 2
        else:
            h += 1
    print(h)
