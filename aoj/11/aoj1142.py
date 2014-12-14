m = int(input())
for i in range(m):
    d = input()
    trains = [d]
    for j in range(1, len(d)):
        f, b = d[:j], d[j:]
        rf, rb = f[::-1], b[::-1]
        trains.extend([rf+b, f+rb, rf+rb, b+f, rb+f, b+rf, rb+rf])
    print(len(set(trains)))
