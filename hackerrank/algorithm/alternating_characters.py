for _ in range(int(input())):
    S = input()
    print(sum(1 for i in range(len(S)-1) if S[i] == S[i+1]))
