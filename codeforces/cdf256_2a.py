import math
need = math.ceil(sum(int(x) for x in input().split())/5) + math.ceil(sum(int(x) for x in input().split())/10)
N = int(input())
print('YES' if N >= need else 'NO')
