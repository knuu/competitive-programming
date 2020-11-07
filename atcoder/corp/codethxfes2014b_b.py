l = [int(input()) for _ in range(3)]
a, b = l[0]+l[1], l[0]*l[1]
print(max(a+l[2], a*l[2], b+l[2], b*l[2]))
