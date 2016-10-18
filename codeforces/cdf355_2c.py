def rev(c):
    if c.isdigit():
        return ord(c) - ord('0')
    elif c.isupper():
        return 10 + ord(c) - ord('A')
    elif c.islower():
        return 36 + ord(c) - ord('a')
    elif c == '-':
        return 62
    else:
        return 63

counter = [0] * 64
for i in range(64):
    for j in range(64):
        counter[i & j] += 1
ans = 1
mod = int(1e9+7)
for s in input():
    ans *= counter[rev(s)]
    ans %= mod
print(ans)
