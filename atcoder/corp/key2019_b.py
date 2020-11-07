S = input()
N = len(S)
key = "keyence"
for i in range(N + 1):
    for j in range(i, N + 1):
        if S[:i] + S[j:] == key:
            print("YES")
            quit()
print("NO")
