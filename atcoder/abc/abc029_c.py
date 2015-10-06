from itertools import product
print(*[''.join(x) for x in product('abc', repeat=int(input()))], sep='\n')
