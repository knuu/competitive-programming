na, nb = map(int, input().split())
a = map(int, input().split())
b = map(int, input().split())
dic = dict([])
for i in a:
    dic[i] = dic.get(i, 0) + 1
for i in b:
    dic[i] = dic.get(i, 0) + 1
an, o = 0, 0
for key in dic.keys():
    if dic[key] == 2:
        an += 1
    o += 1
print(an / o)
