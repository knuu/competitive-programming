N = int(input())
A = [int(x) for x in input().split()]
print(min(sum((a-x)**2 for a in A) for x in range(-100, 101)))
