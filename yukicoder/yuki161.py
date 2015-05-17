yuki = list(map(int, input().split()))
S = input()
enemy = [S.count('G'), S.count('C'), S.count('P')]
ans = 0
for i in range(3):
    ans += min(yuki[i], enemy[(i+1)%3]) * 3
    yuki[i], enemy[(i+1)%3] = max(0, yuki[i]-enemy[(i+1)%3]), max(0, enemy[(i+1)%3]-yuki[i])

for i in range(3):
    ans += min(yuki[i], enemy[i])
print(ans)
