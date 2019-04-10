K = int(input())
fib = [1, 1]
for _ in range(K-1):
    fib.append(fib[-1] + fib[-2])
print(fib[-2], fib[-1])
assert(fib[-1] <= 10**9)
