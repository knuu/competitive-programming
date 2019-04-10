from math import factorial
def f(X, Y):
    valid = [set() for _ in range(X+Y+1)]
    valid[0].add('')
    for i in range(X+Y):
        for v in valid[i]:
            valid[i+1].add('[' + v + ']')
            if '[' not in v:
                valid[i+1].add('(' + v + ')')
        for j in range(1, i+1):
            for v1 in valid[j]:
                for v2 in valid[i+1-j]:
                    valid[i+1].add(v1+v2)
    ans = [v for v in valid[X+Y] if v.count('[') == X]
    return len(ans)

mod = 10**9+7
for _ in range(int(input())):
    X, Y = map(int, input().split())
    print(f(X, Y) * factorial(X) % mod * factorial(Y) % mod)
