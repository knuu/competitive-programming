n, a, b = map(int, input().split())
rem = n % (a + b)
if 0 < rem <= a:
    print('Ant')
else:
    print('Bug')
