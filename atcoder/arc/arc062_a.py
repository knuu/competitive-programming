N = int(input())
T = A = 1
for _ in range(N):
    t, a = map(int, input().split())
    k = max([1, T // t + (T % t != 0), A // a + (A % a != 0)])
    T, A = k * t, k * a
print(T + A)
