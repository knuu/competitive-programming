N = input()
print('SAME' if all(N[0] == n for n in N) else 'DIFFERENT')
