p = [input() for _ in range(10)]
print('Yes' if all(any(p[j][i] == 'o' for j in range(10)) for i in range(10)) else 'No')
