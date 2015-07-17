A = int(input())
print(max([i * (A - i) for i in range(1, A)]))
