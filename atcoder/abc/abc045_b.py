players = dict(zip('abc', [list(input())[::-1] for _ in range(3)]))
now = 'a'

while players[now]:
    now = players[now].pop()
print(now.upper())
