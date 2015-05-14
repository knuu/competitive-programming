N = int(input())
X = sorted(list(set(map(int, input().split()))))
print(0 if len(X) == 1 else min([abs(X[i]-X[i+1]) for i in range(len(X)-1)]))
