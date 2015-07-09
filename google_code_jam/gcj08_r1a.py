f = open("A-large-practice.in")
s = f.readlines()

N = int(s[0])
s = s[1:]

for i in range(0, len(s[1:]), 3):
    n = int(s[i])
    x = list(map(int, s[i+1].split()))
    y = list(map(int, s[i+2].split()))
    x.sort()
    y.sort()
    ans = sum([xi*yi for xi, yi in zip(x, y[::-1])])
    print("Case #{}: {}".format(i//3 + 1, ans))
f.close()
