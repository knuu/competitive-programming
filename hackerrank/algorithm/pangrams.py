from collections import Counter
from string import ascii_lowercase
c = Counter(input().lower())
for s in ascii_lowercase:
    if not c[s]:
        print('not pangram')
        break
else:
    print('pangram')
