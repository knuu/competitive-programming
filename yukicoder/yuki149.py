Aw, Ab = map(int, input().split())
Bw, Bb = map(int, input().split())
C, D = map(int, input().split())
if C > Ab:
    Bw += C-Ab; Aw -= C-Ab
    Bb += Ab; Ab = 0
else:
    Bb += C; Ab -= C

if D > Bw:
    print(Aw + Bw)
else:
    print(Aw + D)
