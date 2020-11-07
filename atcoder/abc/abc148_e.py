N = int(input())
if N % 2 == 1:
    print(0)
    quit()

cnt = 0
M = 5 * 2
while M <= N:
    cnt += N // M
    M *= 5
print(cnt)
