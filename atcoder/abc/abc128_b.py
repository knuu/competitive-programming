N = int(input())
rest = []
for i in range(N):
    name, score = input().split()
    rest.append((name, -int(score), i+1))
rest.sort()
for _, _, i in rest:
    print(i)
