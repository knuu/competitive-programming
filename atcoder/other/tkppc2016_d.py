from fractions import gcd

H, W, K = map(int, input().split())
g = gcd(K, W)

W, K = W//g, K//g
print(K//2*W//2+(K-1)//2*(W-2)//2)
