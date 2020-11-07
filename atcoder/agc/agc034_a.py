N, A, B, C, D = map(int, input().split())
S = "#{}#".format(input())


def reachable(start, end):
    now = start
    while now <= end:
        nex = now
        while nex <= end and S[now] == S[nex]:
            nex += 1
        if S[now] == '#' and nex - now >= 2:
            return False
        now = nex
    return True


if not reachable(A, C) or not reachable(B, D):
    print("No")
    quit()

if C > D:
    can_over = False
    for i in range(B, D+1):
        if S[i-1] == S[i] == S[i+1] == ".":
            can_over = True
    if not can_over:
        print("No")
        quit()

print("Yes")
