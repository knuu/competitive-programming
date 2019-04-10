N = int(input())
points = [tuple(int(x) for x in input().split()) for _ in range(N)]
if any(abs(x + y) % 2 != abs(sum(points[0])) % 2 for x, y in points):
    print(-1)
    quit()
even_flag = abs(sum(points[0])) % 2 == 0
points = [(x + y, x - y) for x, y in points]

M = 31 + even_flag
print(M)
print(*([1] if even_flag else []) + [1 << i for i in range(31)])
d_uv = {(0, 0): "L", (1, 1): "R", (1, 0): "U", (0, 1): "D"}
for u, v in points:
    ans = []
    if even_flag:
        ans.append("R")
        u, v = u - 1, v - 1
    sum_d_u = (u + (1 << 31) - 1) // 2
    sum_d_v = (v + (1 << 31) - 1) // 2
    for i in range(31):
        u_flag = sum_d_u >> i & 1
        v_flag = sum_d_v >> i & 1
        ans.append(d_uv[u_flag, v_flag])
    print(''.join(ans))
