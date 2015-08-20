range = xrange; input = raw_input
for _ in range(int(input())):
    print((lambda x, y: x + y)(*map(int, input().split())))
