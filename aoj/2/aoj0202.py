from math import sqrt
class Prime:
    """ make prime numbers lists """

    def __init__(self, n):
        self.is_prime = [True for _ in range(n+1)]
        self.primeList = []
        self.is_prime[0] = False
        self.is_prime[1] = False
        for i in range(2, int(pow(n, 0.5))+1):
            if self.is_prime[i] == True:
                self.primeList.append(i)
                for j in range(2*i, n+1, i):
                    self.is_prime[j] = False

    def isPrime(self, n):
        return self.is_prime[n]

    def nthPrime(self, n):
        return self.primeList[n-1]

prime = Prime(10**6)
while True:
    N, X = map(int, input().split())
    if (N, X) == (0, 0): break
    price = [int(input()) for _ in range(N)]
    dp = [0] * (X+1)
    dp[0] = 1
    for i in range(X+1):
        if dp[i] == 0: continue
        for p in price:
            if i + p <= X:
                dp[i+p] = 1
    for i in range(X, -1, -1):
        if dp[i] == 1 and prime.isPrime(i) == 1:
            print(i)
            break
    else:
        print('NA')
