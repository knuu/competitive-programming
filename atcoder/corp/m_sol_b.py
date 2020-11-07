S = input()
o, x = S.count("o"), S.count("x")
res = 15 - len(S)
print("YES" if o + res > x else "NO")
