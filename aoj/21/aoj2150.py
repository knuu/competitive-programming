sieve = [True] * 110000
primes = []
for i in range(2, 110000):
    if sieve[i] == True:
        primes.append(i)
        for j in range(2*i, 110000, i):
            sieve[j] = False

while True:
    n, p = map(int, input().split())
    if n == -1 and p == -1: break
    cnt = 0
    for i in primes:
        if n < i: 
            break
        else: 
            cnt += 1
    psum = sorted([primes[i]+primes[j] for j in range(cnt, cnt+p) for i in range(j, cnt+p)])
    print(psum[p-1])
    
    
