def inv(x):
    return pow(x, mod - 2, mod)

H, W, A, B = map(int, input().split())
mod = 10**9 + 7
t = 1

num = []
for i in range(B-1):
    t *= B-1-i
    t %= mod
num.append(t)
for i in range(H-A-1):
    t *= B+i
    t %= mod
    t *= inv(i+1)
    t %= mod
    num.append(t)
num2 = []
t = 1
for i in range(W-B-1):
    t *= W-B+H-2-i
    t %= mod
num2.append(t)
for i in range(H-A-1):
    t *= W-B-H-2+i+1
    t %= mod
    t *= inv(H-i)
    t %= mod
ans = 0
for t1, t2 in zip(num, num2):
    ans += t1 * t2 % mod
    ans %= mod
for i in range(B-1):
    ans *= inv(i+1)
    ans %= mod
for i in range(W-B-1):
    ans *= inv(i+1)
    ans %= mod
print(ans)
