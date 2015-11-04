def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input()) for _ in range(N)]

N, Q = read_list(int)
array = read_list(int)
C = [[0, 0, 0]]
for a in array:
    c = C[-1][:]
    c[a % 3] += 1
    C.append(c)

for _ in range(Q):
    l, r = read_list(int)
    c1, c2 = C[l-1], C[r]
    if c2[0] - c1[0] == 1:
        print(0)
    else:
        print(2 if (c2[2]-c1[2]) % 2 == 1 else 1)
