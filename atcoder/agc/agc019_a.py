Q, H, S, D = map(int, input().split())
N = int(input())
S = min([Q * 4, H * 2, S])
if S * 2 < D:
    print(N * S)
else:
    print(N // 2 * D + (N % 2) * S)
