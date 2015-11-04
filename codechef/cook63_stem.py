input = raw_input; range = xrange
for _ in range(int(input())):
    N = int(input())
    words = sorted(input().split(), key=lambda x: len(x))
    ans = ''
    s = len(words[0])
    for i in range(s):
        for j in range(i, s):
            sub = words[0][i:j+1]
            assert(len(sub) >= 1)
            if all(sub in x for x in words):
                if len(ans) < len(sub):
                    ans = sub[:]
                elif len(ans) == len(sub) and sub < ans:
                    ans = sub[:]
    assert(len(ans) >= 1)
    print(ans)
