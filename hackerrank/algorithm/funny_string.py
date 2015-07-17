for _ in range(int(input())):
    S = input()
    N = len(S)
    for i in range(1, N):
        if abs(ord(S[i]) - ord(S[i-1])) != abs(ord(S[N-i-1]) - ord(S[N-i])):
            print('Not Funny')
            break
    else:
        print('Funny')
