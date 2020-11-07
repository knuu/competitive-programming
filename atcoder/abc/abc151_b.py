N, K, M = map(int, input().split())
score = sum(map(int, input().split()))
need = max(M * N - score, 0)
print(-1 if need > K else need)
