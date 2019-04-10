a, b = map(int, input().split())
if a * b <= 0:
    print("Zero")
else:
    assert(a > 0 or b < 0)
    if a > 0:
        print("Positive")
    else:
        print("Positive" if abs(a-b+1) % 2 == 0 else "Negative")
