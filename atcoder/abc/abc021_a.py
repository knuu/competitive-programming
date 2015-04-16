n = int(input())

ans = [2 for i in range(n//2)]
if n % 2 != 0: ans.append(1)
print(len(ans))
for i in ans: print(i)
