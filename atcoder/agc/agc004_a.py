A, B, C = map(int, input().split())

print(0 if any(i % 2 == 0 for i in [A, B, C]) else min([A*B, B*C, C*A]))
