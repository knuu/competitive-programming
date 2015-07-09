N = int(input())
A = list(map(int, input().split()))
B = list(map(lambda x: int(x)-1, input().split()))
bucket = [0]*100
K = 0
for a, b in zip(A, B):
    if b == -1:
        K += a
    else:
        bucket[b] += a
print('YES' if max(bucket) <= K else 'NO')
