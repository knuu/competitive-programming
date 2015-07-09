N = int(input())
N %= 30
S = list('123456')
for i in range(N):
    S[i%5], S[i%5+1] = S[i%5+1], S[i%5]
print(''.join(S))
