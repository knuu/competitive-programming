W, H, C = input().split()
W, H = int(W), int(H)
pat = ['W', 'B'] if C == 'W' else ['B', 'W']
print('\n'.join([''.join([pat[(i+j)%2] for j in range(W)]) for i in range(H)]))
