N = int(input())
for i in range(N):
    D = int(input())
    P = list(map(int, input().split()))
    Pmax = max(P)
    pancakes = [0] * (Pmax + 1)
    for p in P:
        pancakes[p] += 1
    ans = []
    spe_time = 0
    while Pmax > 1:
        if pancakes[Pmax] > 0:
            ans.append(Pmax + spe_time)
            spe_time += pancakes[Pmax]
            if Pmax % 2 == 0:
                pancakes[Pmax//2] += pancakes[Pmax] * 2
            else:
                pancakes[Pmax//2] += pancakes[Pmax]
                pancakes[Pmax//2 + 1] += pancakes[Pmax]
        Pmax -= 1
    ans.append(pancakes[1] + spe_time)
    print("Case #{}: {}".format(i+1, min(ans)))
    


    
