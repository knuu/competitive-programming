import bisect
N, M = map(int, input().split())
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]
A.sort()
B.sort()
if len(set(A)) != N or len(set(B)) != M:
    print(0)
    quit()
if A[-1] != N * M or B[-1] != N * M:
    print(0)
    quit()
ans = 1
mod = 10 ** 9 + 7
for i in reversed(range(1, N * M + 1)):
    ai = bisect.bisect_left(A, i)
    bi = bisect.bisect_left(B, i)
    a_flag = A[ai] == i
    b_flag = B[bi] == i
    if a_flag and b_flag:
        pass
    elif a_flag:
        cand = M - bi
        ans = (ans * cand) % mod
    elif b_flag:
        cand = N - ai
        ans = (ans * cand) % mod
    else:
        cand = (N - ai) * (M - bi) - (N * M - i)
        if cand <= 0:
            print(0)
            quit()
        ans = (ans * cand) % mod
print(ans)
