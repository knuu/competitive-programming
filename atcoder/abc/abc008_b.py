N = int(input())
dic = {}
for i in range(N):
    cand = input()
    dic[cand] = dic.get(cand, 0) + 1
revdic = {}
for key in dic.keys():
    revdic[dic[key]] = key
print(revdic[max(revdic.keys())])
