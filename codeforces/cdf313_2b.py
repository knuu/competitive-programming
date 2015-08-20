def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input()) for _ in range(N)]

R = sorted(read_list(int))
a2, b2 = read_list(int)
a3, b3 = read_list(int)

R1 = sorted([a2+a3, max(b2, b3)])
R2 = sorted([a2+b3, max(b2, a3)])
R3 = sorted([b2+a3, max(a2, b3)])
R4 = sorted([b2+b3, max(a2, a3)])
if R1[0] <= R[0] and R1[1] <= R[1] \
   or R2[0] <= R[0] and R2[1] <= R[1] \
   or R3[0] <= R[0] and R3[1] <= R[1] \
   or R4[0] <= R[0] and R4[1] <= R[1]:
    print('YES')
else:
    print('NO')

    
