def bubbleSort(l, n):
    for i in range(n):
        for j in range(n-1-i):
            if l[j][0] > l[j+1][0]:
                l[j], l[j+1] = l[j+1], l[j]
    return l[:]

def selectionSort(l, n):
    for i in range(n):
        minj = i
        for j in range(i+1, n):
            if l[j][0] < l[minj][0]:
                minj = j
        l[i], l[minj] = l[minj], l[i]
    return l[:]

n = int(input())
l = []
for c in input().split():
    l.append((int(c[1]), c[0]))
    
bl = ' '.join([k + str(n) for n, k in bubbleSort(l[:], n)])
sl = ' '.join([k + str(n) for n, k in selectionSort(l[:], n)])
print(bl)
print('Stable')
print(sl)
print('Stable' if sl == bl else 'Not stable')
