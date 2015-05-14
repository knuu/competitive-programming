K, N, F = map(int, input().split())
bean = sum(map(int, input().split()))
print(-1 if bean>K*N else K*N-bean)
