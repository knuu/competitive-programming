from collections import Counter
while True:
    N = int(input())
    if not N:
        break
    C = input().split()
    for i in range(N):
        cnt = Counter(C[:i+1]).most_common() + [('', 0)]
        if cnt[0][1] > cnt[1][1] + N - i - 1:
            print(cnt[0][0], i + 1)
            break
    else:
        print("TIE")
