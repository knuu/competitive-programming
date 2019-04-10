N = int(input())
S = input()
for kind1 in range(2):
    for kind2 in range(2):
        T = [0] * (N + 2)
        T[0] = kind1
        T[1] = kind2
        for i in range(1, N + 1):
            if T[i] == 0 and S[i % N] == 'o':
                T[i + 1] = T[i - 1]
            elif T[i] == 0 and S[i % N] == 'x':
                T[i + 1] = T[i - 1] ^ 1
            elif T[i] == 1 and S[i % N] == 'o':
                T[i + 1] = T[i - 1] ^ 1
            else:
                T[i + 1] = T[i - 1]
        if T[0] == T[-2] and T[1] == T[-1]:
            print(''.join("SW"[t] for t in T[:-2]))
            quit()
print(-1)
