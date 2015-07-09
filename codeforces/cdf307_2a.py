rating = [0]*2001
n = int(input())
R = list(map(int, input().split()))

for r in R:
    rating[r] += 1
rank = 1
ratingRank = [0]*2001
for i in range(2000, -1, -1):
    ratingRank[i] = rank
    rank += rating[i]
print(*[ratingRank[r] for r in R])


