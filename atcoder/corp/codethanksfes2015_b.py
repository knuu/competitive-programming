A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]
C = int(input())
ans = []
if C in A:
    ans.extend(B)
if C in B:
    ans.extend(A)
ans = set(ans)
print(len(ans))
print(*sorted(ans), sep='\n')
