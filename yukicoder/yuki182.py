N = int(input())
dic = dict()
for a in map(int, input().split()):
    dic[a] = dic.get(a, 0) + 1
print(list(dic.values()).count(1))
    
