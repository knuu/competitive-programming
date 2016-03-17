N, a, b, c = int(input()), int(input()), int(input()), int(input())
ans = 0
if b - c < a and N >= b:
    ans += (N - b) // (b - c) + 1
    N = (N - b) % (b - c) + c
print(ans + N // a)
