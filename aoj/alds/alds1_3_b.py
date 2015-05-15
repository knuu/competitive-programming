from queue import Queue
n, q = map(int, input().split())
que = Queue()
for i in range(n):
    name, time = input().split()
    que.put((name, int(time)))

total = 0
while que.qsize() > 0:
    name, time = que.get()
    total += min(q, time)
    if q < time:
        que.put((name, time-q))
    else:
        print(name, total)
