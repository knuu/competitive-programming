N = int(input())
yes_set = []
k = 1
while k * (k + 1) < 2 * N:
    k += 1
if k * (k + 1) != 2 * N:
    print("No")
    quit()
ans = []
x = 1
for i in range(k + 1):
    row = []
    for j in range(i):
        row.append(ans[j][i - 1])
    for j in range(k - i):
        row.append(x)
        x += 1
    ans.append(row)
print("Yes")
print(k + 1)
for row in ans:
    print("{} {}".format(k, ' '.join(map(str, row))))
