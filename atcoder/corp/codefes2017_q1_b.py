N, M, K = map(int, input().split())
for r in range(N + 1):
    black = r * M
    b_c, w_c = r, N - r
    for c in range(M + 1):
        if black - b_c * c + w_c * c == K:
            print("Yes")
            quit()
print("No")
