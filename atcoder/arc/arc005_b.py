def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input()) for _ in range(N)]

y, x, W = read_list(str)
x = int(x) - 1; y = int(y) - 1
rand = [[int(x) for x in read_line(str)] for _ in range(9)]

def enc(x):
    if x < 0:
        return enc(abs(x))
    elif x >= 9:
        return enc(16 - x)
    else:
        return x

dxy = {'U': (-1, 0), 'L': (0, -1), 'D': (1, 0), 'R': (0, 1),
       'RU': (-1, 1), 'RD': (1, 1), 'LU': (-1, -1), 'LD': (1, -1)}

ans = []
for i in range(4):
    ans.append(rand[enc(x)][enc(y)])
    nx, ny = dxy[W]
    x += nx; y += ny
print(''.join(map(str, ans)))
