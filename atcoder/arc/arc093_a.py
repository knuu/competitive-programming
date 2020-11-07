N = int(input())
A = [int(x) for x in input().split()]

all_cost = 0
prev = 0
for a in A:
    all_cost += abs(a-prev)
    prev = a
all_cost += abs(A[-1])

prev = 0
for i, a in enumerate(A[:-1]):
    print(all_cost - abs(a-prev) - abs(a-A[i+1]) + abs(A[i+1]-prev))
    prev = a
print(all_cost - abs(A[-2]-A[-1]) - abs(A[-1]) + abs(A[-2]))
