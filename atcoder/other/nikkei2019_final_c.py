def calc_med(A, num):
    acc = 0
    for i, a in enumerate(A):
        if acc <= num // 2 < acc + a:
            return i
        acc += a
    return len(A) - 1

def calc_sum(A, x):
    ret = 0
    for i, a in enumerate(A):
        ret += abs(x - i) * a
    return ret

H, W, K = map(int, input().split())
R = [W for i in range(H)]
C = [H for i in range(W)]
for _ in range(K):
    r, c = map(int, input().split())
    R[r - 1] -= 1
    C[c - 1] -= 1

R_med = calc_med(R, H * W - K)
C_med = calc_med(C, H * W - K)
#print(R, C, R_med, C_med)
print(calc_sum(R, R_med) + calc_sum(C, C_med))
