from collections import Counter

cnt = Counter(input())

print("No" if sum(x in cnt for x in "NS") == 1 or sum(x in cnt for x in "WE") == 1 else "Yes")
