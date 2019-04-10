def parser(l, r):
    if all(S[i].isdigit() for i in range(l, r + 1)):
        return int(S[l:r + 1]) // 2 + 1
    ret = []
    cnt = 0
    start = 0
    for i in range(l, r + 1):
        if S[i] == '[':
            cnt += 1
            if cnt == 1:
                start = i
        elif S[i] == ']':
            if cnt == 1:
                ret.append(parser(start + 1, i - 1))
            cnt -= 1
    ret.sort()
    return sum(ret[:len(ret) // 2 + 1])


N = int(input())
for _ in range(N):
    S = input()
    print(parser(0, len(S) - 1))
