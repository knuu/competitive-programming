N, top = map(int, input().split())
pa = dict()
for i in range(N):
    f, t = map(int, input().split())
    pa[f] = max(pa.get(f, 0), t)
now, time = top, 0
for f, t in sorted(pa.items(), reverse=True):
    time += now - f
    now = f
    time = max(t, time)
else:
    time += now
print(time)
    
