k = int(input())
q = input()
cut = [0]
topset = set([q[0]])
for i in range(1, len(q)):
    if len(cut) == k:
        break
    if q[i] not in topset:
        cut.append(i)
        topset.add(q[i])
        
if len(cut) < k:
    print('NO')
else:
    print('YES')
    for i in range(k-1):
        print(q[cut[i]:cut[i+1]])
    print(q[cut[-1]:])
