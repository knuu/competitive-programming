H, W = map(int, input().split())
S = [input().split() for _ in range(H)]
for r, row in enumerate(S):
    for c, s in enumerate(row):
        if s == "snuke":
            print(chr(ord('A') + c) + str(r + 1))
            quit()
