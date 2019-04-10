pin = ['x'] * 10
_ = input()
for i in range(2):
    for j in map(int, input().split()):
        pin[j] = 'o' if  i else '.'
print('{7} {8} {9} {0}\n {4} {5} {6}\n  {2} {3}\n   {1}'.format(*pin))
