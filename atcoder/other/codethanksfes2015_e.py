for _ in range(int(input())):
    S, T = input().split()
    SS = ''.join([s for s in S if s in T])
    print('YES' if T in SS else 'NO')
