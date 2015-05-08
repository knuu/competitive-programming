n, m = map(int, input().split())
notes = [list(map(int, input().split())) for _ in range(m)]

if m == 1:
    d, h = notes[0]
    print(max(h+(d-1), h+(n-d)))
    exit(0)

d0, h0 = notes[0]
ans = h0+(d0-1)
for i in range(m-1):
    d1, h1 = notes[i]
    d2, h2 = notes[i+1]
    if d2-d1 < abs(h1-h2):
        ans = -1
        break
    else:
        ans = max((h1+h2+(d2-d1))//2, ans)
else:
    dm, hm = notes[m-1]
    ans = max(ans, hm+(n-dm))
print(ans if ans != -1 else 'IMPOSSIBLE')
        
    
