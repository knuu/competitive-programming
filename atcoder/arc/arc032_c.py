n = int(input())

works = []
end = 0
for i in range(n):
    s, t = map(int, input().split())
    works.append([s, t, i+1])
    end = max(end, t)

time = [[] for _ in range(end+1)]
for s, t, i in works:
    time[s].append([t, i])

dp = [[0,0] for _ in range(end+1)]
for i in range(end-1, -1, -1):
    m_w, m_id = 0, n
    for t, w_id in time[i]:
        if m_w < dp[t][0] + 1:
            m_w = dp[t][0] + 1
            m_id = w_id
        elif m_w == dp[t][0] + 1:
            m_id = min(m_id, w_id)
    if dp[i+1][0] < m_w:
        dp[i] = [m_w, m_id]
    elif dp[i+1][0] == m_w:
        dp[i] = [dp[i+1][0], min(dp[i+1][1], m_id)]
    else:
        dp[i] = dp[i+1]

print(dp[0][0])

id_works = [0] * (n+1)
for _, t, i in works:
    id_works[i] = t

id_works[0] = end

w = []
now = 0
while now < end:
    if dp[now][1] != 0:
        w.append(str(dp[now][1]))
    now = id_works[dp[now][1]]

print(' '.join(w))


