n = int(input())
words = [input() for _ in range(n)]
used = []
for i, w in enumerate(words):
    if w in used or (i > 0 and w[0] != used[-1][-1]):
        print('WIN' if i % 2 != 0 else 'LOSE')
        quit()
    used.append(w)
print('DRAW')
