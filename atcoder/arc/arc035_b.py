n = int(input())
T = [int(input()) for _ in range(n)]
Tdic = {}
for t in T:
    Tdic[t] = Tdic.get(t, 0) + 1
T.sort()
print(sum([(len(T)-cnt) * t for cnt, t in enumerate(T)]))
ans = 1
div = 10**9 + 7
def fact(n):
    ret = 1
    for i in range(1,n+1):
        ret = (ret*i) % div
    return ret
for k in Tdic.keys():
    ans = (ans * fact(Tdic[k])) % div
print(ans)
    

