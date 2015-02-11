n, k = map(int, input().split())
days = [(int(x), cnt) for cnt, x in enumerate(input().split())]
days.sort()
ans = []
for day, inst in days:
    if day > k:
        break
    else:
        ans.append(str(inst+1))
        k -= day
print(len(ans))
if ans != []:
    print(' '.join(ans))
