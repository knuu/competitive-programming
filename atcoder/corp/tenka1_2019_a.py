N = int(input())
S = input()
white = [0] * (N + 1)
black = [0] * (N + 1)
bound = [-1]
for i, s in enumerate(S):
    if s == '.':
        white[i + 1] = 1
    else:
        black[i + 1] = 1
    white[i + 1] += white[i]
    black[i + 1] += black[i]
    if i < N - 1 and S[i] == '#' and S[i + 1] == '.':
        bound.append(i)
bound.append(N)

ans = N
for i, j in zip(bound, bound[1:]):
    ans = min(ans, black[i + 1] + white[-1] - white[j])
print(ans)
