from itertools import permutations

T = int(input())


def dfs(l, i, R, C):
    if R < 0 or C < 0:
        return False
    if i == 2:
        return l[i] == R * C
    if R * C == 0:
        return False
    if l[i] % R == 0 and dfs(l, i+1, R, C - l[i] // R):
        return True
    if l[i] % C == 0 and dfs(l, i+1, R - l[i] // C, C):
        return True
    return False


for _ in range(T):
    R, C, M, K, J = map(int, input().split())
    for l in permutations([M, K, J]):
        if dfs(l, 0, R, C):
            print("Yes")
            break
    else:
        print("No")
