tformat = lambda num, time: '{} {:.2f}'.format(num, time)
runners = [[] for _ in range(3)]
thirds = []
for i in range(3):
    for _ in range(8):
        num, time = input().split()
        runners[i].append((float(time), int(num)))
    runners[i].sort()
    thirds += runners[i][2:]
thirds.sort()
for run in runners:
    for time, num in run[:2]:
        print(tformat(num, time))
for time, num in thirds[:2]:
    print(tformat(num, time))
