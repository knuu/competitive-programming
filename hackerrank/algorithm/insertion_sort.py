N = int(input())
array = [int(x) for x in input().split()]
last = array[-1]
for i in range(1, N):
    if last < array[-i-1]:
        array[-i] = array[-i-1]
    else:
        array[-i] = last
        break
    print(*array)
else:
    array[0] = last
print(*array)
