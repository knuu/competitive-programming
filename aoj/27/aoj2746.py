def j2b(S):
    rows = S.split("/")
    for i, row in enumerate(rows):
        cand = []
        for s in row:
            if s == "b":
                cand.append(s)
            else:
                cand.extend(["."] * int(s))
        rows[i] = cand
    return rows


def b2j(rows):
    ret = []
    for row in rows:
        r = []
        c = 0
        for s in row:
            if s == "b":
                if c:
                    r.append(str(c))
                r.append(s)
                c = 0
            else:
                c += 1
        if c:
            r.append(str(c))
        ret.append(''.join(r))
    return '/'.join(ret)


while True:
    S = input()
    if S == "#":
        break
    rows = j2b(S)
    a, b, c, d = [int(x) - 1 for x in input().split()]
    rows[a][b], rows[c][d] = rows[c][d], rows[a][b]
    print(b2j(rows))
