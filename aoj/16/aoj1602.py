def parser(i):
    idx = i
    dep = s[i].count('.')
    i += 1
    arr = []
    while i < N and s[i].count(".") > dep:
        if "+" in s[i] or "*" in s[i]:
            num, i = parser(i)
            arr.append(num)
        else:
            arr.append(int(s[i].replace('.', '')))
        i += 1
    if "+" in s[idx]:
        return sum(arr), i - 1
    else:
        ret = 1
        for num in arr:
            ret *= num
        return ret, i - 1

while True:
    N = int(input())
    if not N:
        break
    if N == 1:
        print(input())
        continue
    s = [input() for _ in range(N)]
    print(parser(0)[0])
