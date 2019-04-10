import heapq, string
for t in range(int(input())):
    N = int(input())
    P = [int(x) for x in input().split()]
    pque = []
    for i, p in enumerate(P):
        heapq.heappush(pque, (-p, string.ascii_uppercase[i]))
    ans, s = [], -sum(p for p, i in pque)
    while pque:
        p, i = heapq.heappop(pque)
        #print(pque)
        if p == -1 and len(pque) == 1 and pque[0][0] == -1:
            ans.append(i+pque[0][1])
            break
        if s-1 < -pque[0][0] * 2:
            p2, i2 = heapq.heappop(pque)
            ans.append(i+i2)
            if p2+1:
                heapq.heappush(pque, (p2+1, i2))
            s -= 1
        else:
            ans.append(i)
        s -= 1
        if p+1:
            heapq.heappush(pque, (p+1, i))

    print("Case #{}: {}".format(t+1, ' '.join(ans)))
