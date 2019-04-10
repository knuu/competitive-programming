d = float(input())
ans = d * pow(2, 0.5)
for i in range(1, 11):
    if i <= d <= pow(1 + i ** 2, 0.5):
        ans = max(ans, i + 1)
print("{:.020f}".format(ans))
