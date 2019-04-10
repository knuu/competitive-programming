import sys
if sys.version[0] == '2':
    range, input = xrange, raw_input
for t in range(int(input())):
    N = int(input())
    topics = [input().split() for _ in range(N)]
    ans = 0
    for state in range(1 << N):  # if bit i == 1 then it is fake
        first_set, second_set, fakes = set(), set(), []
        for i in range(N):
            if state >> i & 1:
                fakes.append(topics[i])
            else:
                first_set.add(topics[i][0])
                second_set.add(topics[i][1])
        if all(first in first_set and second in second_set for first, second in fakes):
            ans = max(ans, len(fakes))
    print("Case #{}: {}".format(t+1, ans))
