class Prime:
    """ make prime numbers lists
        complexity: O(n^(1/2))
        used in AOJ0202
    """

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
        for i in range(int(pow(n, 0.5))+1, n+1):
            if self.is_prime[i] == True:
                self.primeList.append(i)

    def isPrime(self, n):
        return self.is_prime[n]

    def nthPrime(self, n):
        return self.primeList[n-1]
