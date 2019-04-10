a, b, c = map(int, input().split())
if c == 0:
    print("YES" if a == b else "NO")
else:
    print("YES" if (b - a + c) % c == 0 and (b - a + c) // c > 0 else "NO")
