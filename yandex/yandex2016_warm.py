S = input()
c, v = [], []
for s in S:
    if s in 'aiueoy':
        v.append(s)
    else:
        c.append(s)
c, v = ''.join(c), ''.join(v)
print("Consonant" if c > v else "Vowel")
