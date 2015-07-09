N, A, B = map(int, input().split())
pos = 0
for i in range(N):
    s, d = input().split()
    d = min(max(int(d), A), B)
    if s == 'East':
        pos += d
    else:
        pos -= d
print('{} {}'.format('East' if pos > 0 else 'West', abs(pos)) if pos else 0)
