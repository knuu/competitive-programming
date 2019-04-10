N = int(input())
sticks = dict()
for a in map(int, input().split()):
    sticks[a] = sticks.get(a, 0) + 1
sticks = sorted([(k, v) for k, v in sticks.items() if v >= 2], reverse=True)
if len(sticks) == 0 or (len(sticks) == 1 and sticks[0][1] < 4):
    print(0)
elif sticks[0][1] >= 4:
    print(sticks[0][0] ** 2)
else:
    print(sticks[0][0] * sticks[1][0])
