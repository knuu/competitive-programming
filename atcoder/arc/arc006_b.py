def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input()) for _ in range(N)]

N, L = read_list(int)
amida = [input() for _ in range(L+1)]
hit = amida[-1].index('o')
for i in reversed(range(L)):
    if hit > 0 and amida[i][hit-1] == '-':
        hit -= 2
    elif hit < N * 2 - 2 and amida[i][hit+1] == '-':
        hit += 2
print(hit // 2 + 1)
