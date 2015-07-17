from collections import defaultdict
N = int(input())
A = [int(x) for x in input().split()]

bucket = defaultdict(list)
for i, num in enumerate(A):
    bucket[num].append(i)

sorted_buckets = sorted(bucket.values(), key=lambda val: (-len(val), val[-1]-val[0]))
print(sorted_buckets[0][0]+1, sorted_buckets[0][-1]+1)
