def loop_detect(start):
    now = start
    loop = [-1] * N
    index = 0
    while True:
        if loop[now] > -1:
            break
        loop[now] = index
        index += 1
        now = B[now]
    return now, index - loop[now]


N, a = map(int, input().split())
a -= 1
k = int(input())
B = [int(x)-1 for x in input().split()]

loop_start, loop_length = loop_detect(a)

while k > 0:
    if a == loop_start:
        k %= loop_length
        if not k:
            break
    a = B[a]
    k -= 1
print(a + 1)
