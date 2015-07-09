while True:
    N = int(input())
    if not N: break
    ans = float('inf')
    for c200 in range(N//200+1):
        for c300 in range(N//300+1):
            for c500 in range(N//500+1):
                if 200 * c200 + c300 * 300 + c500 * 500 == N:
                    ans = min(ans, 1520*(c200//5)+380*(c200%5)+1870*(c300//4)+550*(c300%4)+2244*(c500//3)+850*(c500%3))
    print(ans)
