S = input()
if all(S[0] == x for x in S):
    print(len(S))
else:
    print(min(max(i + 1, len(S) - (i + 1)) for i in range(len(S) - 1) if S[i] != S[i + 1]))
