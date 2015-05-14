N = int(input())
L = list(map(lambda x:int(x)-1, input().split()))
q = [L.count(i) for i in range(6)][::-1]
print(6-q.index(max(q)))
