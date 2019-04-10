L, X, Y, S, D = map(int, input().split())
F, B = X+Y, Y-X
FD, BD = D - S if D > S else (L + D - S) % L, S - D if S > D else (S + L - D) % L
if B <= 0:
    print(FD / F)
else:
    print(FD / F if FD * B < BD * F else BD / B)
