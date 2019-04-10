from copy import deepcopy
from functools import reduce


class Divisor:
    def __init__(self, n):
        """ make divisors list and prime factorization list of n
            complexity: O(n^(1/2))
            used in ProjectEuler No.12, yukicoder No.36
        """
        assert(n >= 1)
        number = n
        if number == 1:
            self.primeFactorization = {1: 1}
        else:
            self.primeFactorization = {}
            for i in range(2, int(n**0.5)+1):
                cnt = 0
                while number % i == 0:
                    cnt += 1
                    number //= i
                if cnt > 0:
                    self.primeFactorization[i] = cnt
            if number > 1:
                self.primeFactorization[number] = 1

T = int(input())
for _ in range(T):
