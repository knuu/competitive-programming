from collections import Counter
_ = int(input())
for key, val in Counter(input().split()).items():
    if val == 1:
        print(key)
