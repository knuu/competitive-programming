bucketA = [0]*26
bucketB = [0]*26
for s in input():
    bucketA[ord(s)-ord('a')] += 1
for s in input():
    bucketB[ord(s)-ord('a')] += 1
print('YES' if bucketA == bucketB else 'NO')


