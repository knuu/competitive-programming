S, T = list(input()), list(input())
p_t, lenT = 0, len(T)
lenS = len(S)
for s in S:
    if s == T[p_t]:
        p_t += 1
        if p_t == lenT:
            print('automaton')
            exit(0)

for t in T:
    for i, s in enumerate(S):
        if S[i] != 0 and t == s:
            S[i] = 0
            break
    else:
        print('need tree')
        exit(0)
print('array' if lenS == lenT else 'both')
        
    
    
