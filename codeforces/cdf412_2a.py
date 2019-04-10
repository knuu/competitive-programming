N = int(input())
ratings = [tuple(int(x) for x in input().split()) for _ in range(N)]
if any(a != b for a, b in ratings):
    print("rated")
elif sorted(ratings, reverse=True) == ratings:
    print("maybe")
else:
    print("unrated")
