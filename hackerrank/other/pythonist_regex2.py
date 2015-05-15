import re
N = input()
valid = re.compile(r'^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$')
ans = valid.match(N)
print(ans != None)
