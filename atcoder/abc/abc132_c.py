N = int(input())
D = [int(x) for x in input().split()]
D.sort()
half = N // 2
print(D[half] - D[half - 1])
