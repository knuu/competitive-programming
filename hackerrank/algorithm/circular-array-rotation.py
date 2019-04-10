n, k, q = map(int, input().split())
A = [int(x) for x in input().split()]
for _ in range(q):
    print(A[(int(input()) - k + n) % n])
