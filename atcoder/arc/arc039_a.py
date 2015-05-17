A, B = input().split()
ans = int(A)-int(B)
for i in range(3):
    for j in range(10):
        AA = int(A[:i]+str(j)+A[i+1:])
        if AA >= 100:
            ans = max(ans, AA-int(B))
for i in range(3):
    for j in range(10):
        BB = int(B[:i]+str(j)+B[i+1:])
        if BB >= 100:
            ans = max(ans, int(A)-BB)
print(ans)
    
