N = int(input())
if sum(int(x) % 2 for x in input().split()) % 2 == 1:
    print("NO")
else:
    print("YES")
