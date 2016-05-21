import sys
if sys.version[0] == '2':
    range, input = xrange, raw_input
N = int(input())
people = [[int(x) for x in input().split()] for _ in range(N)]
ratings = [[0, 0, 0] for _ in range(100001)]
for r, h in people:
    ratings[r][h-1] += 1
ratesum = [0] * 100001
for i in range(100000):
    ratesum[i+1] = sum(ratings[i+1]) + ratesum[i]
for r, h in people:
    print(ratesum[r-1] + ratings[r][h % 3], ratesum[100000] - ratesum[r] + ratings[r][(h+1) % 3], ratings[r][h-1]-1)
