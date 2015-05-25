k, n, w = map(int, input().split())
print(max(sum(k*(i+1) for i in range(w)) - n , 0))
