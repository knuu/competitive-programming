sieve = [0] * 300001
for i in range(6, 300000, 7):
    sieve[i] = sieve[i+2] = 1

MSprimes = []
for i in range(6, 300000, 7):
    if sieve[i] == 1:
        MSprimes.append(i)
        for j in range(2*i, 300000, i):
            sieve[j] = 0
    if sieve[i+2] == 1:
        MSprimes.append(i+2)
        for j in range(2*(i+2), 300000, i+2):
            sieve[j] = 0

while True:
    N = int(input())
    if N == 1: break
    ansp = [x for x in MSprimes if N % x == 0]
    print('{}: {}'.format(N, ' '.join(map(str, ansp))))
