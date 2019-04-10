from collections import Counter
print("Yes" if all(x % 2 == 0 for x in Counter(input()).values()) else "No")
