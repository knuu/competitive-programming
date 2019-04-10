cnt = 0
for _ in range(int(input())):
    cnt += [-1, 1][input() == "A"]
    if cnt < 0:
        print("NO")
        quit()
print("YES" if cnt == 0 else "NO")
