N, M, D = map(int, input().split())

def f(N, M, D):
    if D == 0:
        return (N - D) * (M - 1) / N / N
    else:
        return (N - D) * 2 * (M - 1) / N / N
print(f(N, M, D))
