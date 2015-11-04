from fractions import Fraction

while True:
    s = input()
    if s == '#':
        break
    if s[-1] == 't':
        ans = Fraction(90)
        s = s[:-4]
    else:
        ans = Fraction(0)
        s = s[:-5]
    i = 1
    while s:
        if s[-1] == 't':
            ans += Fraction(90, 1 << i)
            s = s[:-4]
        else:
            ans -= Fraction(90, 1 << i)
            s = s[:-5]
        i += 1
    print(ans)
