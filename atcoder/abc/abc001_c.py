deg, dis = map(int, input().split())

dis = int(dis/6.0 + 0.5) / 10.0

wp = 0
wl = [0.3, 1.6, 3.4, 5.5, 8.0, 10.8, 13.9, 17.2, 20.8, 24.5, 28.5, 32.7]
for w in wl:
    if dis < w:
        break
    wp += 1
wd = 'N'
dl = [(112.5, 'NNE'), (337.5, 'NE'), (562.5, 'ENE'), (787.5, 'E'), (1012.5, 'ESE'), (1237.5, 'SE'), (1462.5, 'SSE'), (1687.5, 'S'), (1912.5, 'SSW'), (2137.5, 'SW'), (2362.5, 'WSW'), (2587.5, 'W'), (2812.5, 'WNW'), (3037.5, 'NW'), (3262.5, 'NNW'), (3487.5, 'N')]
for d, w in dl:
    if deg < d:
        break
    wd = w
if wp == 0:
    wd = 'C'

print(wd, wp)
