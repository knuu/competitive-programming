S = input()
arr = []
now = []
counter = 0
for s in S:
    now.append(s.lower())
    if s.isupper():
        if counter == 0:
            counter += 1
        else:
            arr.append(''.join(now))
            now = []
            counter = 0
arr.sort()
for word in arr:
    for i, s in enumerate(word):
        if i == 0 or i == len(word) - 1:
            print(s.upper(), end='')
        else:
            print(s, end='')
print()
