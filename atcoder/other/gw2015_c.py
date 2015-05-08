import sys
H, W = map(int, input().split())

if H * W % 2 == 1:
    print('First')
    sys.stdout.flush()
    print('{} {} 0'.format(H//2+1, W//2+1))
    sys.stdout.flush()
    while True:
        A, B, C = map(int, input().split())
        if A == -1 and B == -1 and C == -1:
            exit(0)
        else:
            print('{} {} {}'.format(H+1-A, W+1-B, C))
            sys.stdout.flush()
else:
    print('Second')
    sys.stdout.flush()
    while True:
        A, B, C = map(int, input().split())
        if A == -1 and B == -1 and C == -1:
            exit(0)
        else:
            print('{} {} {}'.format(H+1-A, W+1-B, C^1))
            sys.stdout.flush()
