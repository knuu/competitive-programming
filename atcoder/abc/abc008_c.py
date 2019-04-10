N = int(input())
C = [int(input()) for _ in range(N)]

divisor_count = [0] * N
for i in range(N):
    for j in range(N):
        if i != j and C[i] % C[j] == 0:
            divisor_count[i] += 1
print('{:.20f}'.format(sum(0.5 if c % 2 else (c + 2) / (c + 1) / 2 for c in divisor_count)))
