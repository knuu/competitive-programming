import datetime
T = int(input())
for _ in range(T):
    t1 = datetime.datetime.strptime(input(), '%a %d %b %Y %H:%M:%S %z')
    t2 = datetime.datetime.strptime(input(), '%a %d %b %Y %H:%M:%S %z')
    delta = t1 - t2
    print(abs(int(delta.total_seconds())))
