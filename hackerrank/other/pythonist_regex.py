import re
N = int(input())
valid = re.compile(r"^[7-9]\d{9}$")
for _ in range(N):
    test = input()
    ans = valid.match(test)
    if ans is None:
        print('NO')
    else:
        print('YES')
