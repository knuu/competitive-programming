s = int(input().replace('b', '0').replace('B', '1'), 2)
t = int(input().replace('b', '0').replace('B', '1'), 2)
print(bin(s + t)[2:].replace('0', 'b').replace('1', 'B'))
