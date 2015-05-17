import string
N = int(input())
dic = {s:cnt for cnt, s in enumerate(string.digits + string.ascii_uppercase)}
def toDecimal(s, n):
    return sum(dic[i]*(n**(len(s)-cnt-1)) for cnt, i in enumerate(s))
ans = toDecimal('Z'*12, 36)
for i in range(N):
    v = input()
    m = dic[max(v)] + 1
    ans = min(ans, toDecimal(v, m))
print(ans)
