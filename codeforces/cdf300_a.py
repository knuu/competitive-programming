S = input()
c = 'CODEFORCES'
for i in range(len(S)):
    for j in range(i, len(S)+1):
        if S[:i] + S[j:]== c:
            print('YES')
            exit(0)
print('NO')
        
    
