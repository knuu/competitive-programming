def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input()) for _ in range(N)]

N = read_line(int)
flag = False
s = 1
pro = 4
while s < N:
    s += pro
    flag = not flag
    if s >= N:
        break
    s += pro
    flag = not flag
    pro *= 4
print('Takahashi' if flag else 'Aoki')
