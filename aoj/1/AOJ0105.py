d = {}
while True:
    try:
        w, n = input().split()
        n = int(n)
        if w in d: d[w].append(n)
        else: d[w] = [n]
    except:
        for k in sorted(d):
            print(k)
            print(" ".join(map(str,sorted(d[k]))))
        break
