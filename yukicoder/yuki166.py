H, W, N, K = map(int, input().split())
print('YES' if (H*W)%N==K%N else 'NO')
