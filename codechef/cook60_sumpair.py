for _ in range(int(input())):
    N, D = map(int, input().split())
    array = sorted(map(int, input().split()), reverse=True)
    i = 0
    ans = 0
    while i+1 < N:
        if array[i] - array[i+1] < D:
            ans += array[i] + array[i+1]
            i += 1
        i += 1
    print(ans)
