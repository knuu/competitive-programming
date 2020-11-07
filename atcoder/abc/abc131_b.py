N, L = map(int, input().split())
apples = [L + i for i in range(N)]
abs_sort = [(abs(x), i) for i, x in enumerate(apples)]
abs_sort.sort()
eat = apples[abs_sort[0][1]]
print(sum(apples) - eat)
