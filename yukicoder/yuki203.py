C = input() + input()
print(14 - ['o' * i in C for i in range(15)][::-1].index(True))
