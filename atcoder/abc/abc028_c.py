a = [int(x) for x in input().split()]
aset = set()
for i in range(5):
    for j in range(i+1, 5):
        for k in range(j+1, 5):
            aset.add(a[i] + a[j] + a[k])
print(sorted(aset, reverse=True)[2])
