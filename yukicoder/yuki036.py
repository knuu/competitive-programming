# used in ProjectEuler No.12, yukicoder No.36

from copy import deepcopy
from functools import reduce

class Divisor:
    def __init__(self, n):
        """ make divisors list and prime factorization list of n"""
        number = n
        if number == 1:
            self.primeFactorization = {1: 1}
        else:
            self.primeFactorization = {}
            for i in range(2, int(n**0.5)+1):
                cnt = 0
                while number % i == 0:
                    cnt += 1;
                    number //= i
                if cnt > 0:
                    self.primeFactorization[i] = cnt
            if number > 1:
                self.primeFactorization[number] = 1

    def primeFactors(self):
        return deepcopy(self.primeFactorization)

    def numDivisors(self):
        """ the number of divisors """
        if self.primeFactorization.get(1, 0) == 1:
            return 1
        numDiv = 1
        for _, cnt in self.primeFactorization.items():
            numDiv *= cnt+1
        return numDiv

    def sumDivisors(self):
        return reduce(lambda x, y: x * y, [sum(p**i for i in range(n+1)) for p, n in self.primeFactorization.items()])

N = int(input())
d = Divisor(N)
ps = d.primeFactors()
if len(ps) > 2:
    print('YES')
elif len(ps) == 2:
    for d, cnt in ps.items():
        if cnt > 1:
            print('YES')
            break
    else:
        print('NO')
elif len(ps) == 1:
    for d, cnt in ps.items():
        if cnt > 2:
            print('YES')
            break
    else:
        print('NO')
