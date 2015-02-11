rect = [(i**2+j**2, i, j) for i in range(1,150) for j in range(i+1, 150)]
rect.sort()
while True:
    h, w = map(int, input().split())
    if h == 0 and w == 0: break
    _, n_h, n_w = rect[rect.index((h**2+w**2, h, w))+1]
    print(n_h, n_w)
