import string
S = input()
N = len(S)

for i in range(N):
    if i < N-1 and S[i] == S[i+1]:
        print(i+1, i+2)
        quit()
    elif i < N-2 and S[i] == S[i+2]:
        print(i+1, i+3)
        quit()
print(-1, -1)
