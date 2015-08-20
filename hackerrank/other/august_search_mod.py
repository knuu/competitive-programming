def my_mod(num, mod):
    if mod == 1: return 0
    if num < 0:
        num += abs(num // mod) * mod
    return num - (num // mod) * mod

for _ in range(int(input())):
    A, B = map(int, input().split())
    print(my_mod(A, B))
