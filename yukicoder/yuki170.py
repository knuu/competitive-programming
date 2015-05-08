S = input()
dic = {}
for s in S: dic[s] = dic.get(s, 0) + 1
ans = 1
for i in range(len(S)): ans *= i+1
for k in dic.keys():
    for i in range(dic[k]):
        ans //= i+1
print(ans-1)
