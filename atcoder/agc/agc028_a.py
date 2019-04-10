from fractions import gcd

N, M = map(int, input().split())
S = input()
T = input()

gcd_ = gcd(N, M)
lcm_ = N * M // gcd_
for i in range(gcd_):
    if S[i * N // gcd_] != T[i * M // gcd_]:
        print(-1)
        quit()
print(lcm_)
