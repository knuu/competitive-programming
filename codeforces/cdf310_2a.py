N = int(input())
S = [int(x) for x in input()]
print(N - 2 * min(S.count(0), S.count(1)))
