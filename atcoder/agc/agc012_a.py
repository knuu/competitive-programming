N = int(input())
print(sum(sorted(int(x) for x in input().split())[N::2]))
