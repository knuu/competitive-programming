N = int(input())
K = int(input())
tile = [tuple(map(int, input().split())) for i in range(K)] 
if N % 2 != 0:
    c = int(N / 2 + 0.5)
    if c % 3 == 0:
        red, blue, yellow = 2, 1, 0
    elif c % 3 == 2:
        yellow, red, blue = 2, 1, 0
    elif c % 1 == 1:
        blue, yellow, red = 2, 1, 0
    for i in range(K):
        x, y = tile[i]
        d = max(abs(x-c), abs(y-c))
        if d % 3 == red:
            print(1)
        elif d % 3 == blue:
            print(2)
        elif d % 3 == yellow:
            print(3)
else:
    c = N / 2
    if c % 3 == 0:
        red, blue, yellow = 2, 1, 0
    elif c % 3 == 2:
        yellow, red, blue = 2, 1, 0
    elif c % 1 == 0:
        blue, yellow, red = 2, 1, 0
    c += 0.5
    for i in range(K):
        x, y = tile[i]
        d = max(int(abs(x-c)-0.5), int(abs(y-c)-0.5))
        if d % 3 == red:
            print(1)
        elif d % 3 == blue:
            print(2)
        elif d % 3 == yellow:
            print(3)
    
