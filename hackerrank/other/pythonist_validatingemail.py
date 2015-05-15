import re
N = int(input())
valid = re.compile(r'^[a-zA-Z0-9_-]+@[a-zA-Z0-9]+\.[a-zA-Z0-9]{1,3}$')
l = [input() for _ in range(N)]
print(sorted(list(filter(lambda x: valid.match(x) != None, l))))
