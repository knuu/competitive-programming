
N = int(input())
rain = [0] * (24 * 60 + 2)
for _ in range(N):
    S, E = input().split('-')
    S, E = int(S[:2])*60 + int(S[2:]), int(E[:2])*60 + int(E[2:])
    while S % 5 != 0:
        S -= 1
    while E % 5 != 0:
        E += 1
    rain[S] += 1
    rain[E+1] -= 1
for i in range(24*60+1):
    rain[i+1] += rain[i]
i = 0
while i <= 24 * 60:
    if rain[i] > 0:
        end = i
        while rain[end] > 0:
            end += 1
        else:
            end -= 1
        print('{:02}{:02}-{:02}{:02}'.format(i // 60, i % 60, end // 60, end % 60))
        i = end + 1
    else:
        i += 1
