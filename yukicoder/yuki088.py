S = input()
K = 'oda' if S == 'yukiko' else 'yukiko'
B = [input() for _ in range(8)]
print(S if sum(len([x for x in row if x in 'bw']) for row in B) % 2 == 0 else K)
