from math import factorial


def nCk(n, k):
    return factorial(n) // factorial(k) // factorial(n-k)


N, P = map(int, input().split())
A = [int(x) & 1 for x in input().split()]
even, odd = A.count(0), A.count(1)
print((1 << even) * sum(nCk(odd, i) for i in range(P == 1, odd + 1, 2)))
