N = int(input())
for ans in range(50001):
    if int(ans * 1.08) == N:
        print(ans)
        quit()
print(":(")
