N = int(input())
mark = list(input())
point = [mark.count(str(i+1)) for i in range(4)]
print('{} {}'.format(max(point), min(point)))
