W = int(input())
D = int(input())
task = []
sumTask = 0
for rest in range(D, 1, -1):
    W -= W//rest**2
print(W)
