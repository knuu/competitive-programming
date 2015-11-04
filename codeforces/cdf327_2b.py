import string
N, M = map(int, input().split())
S = input()
dic = string.ascii_lowercase
for _ in range(M):
    x, y = input().split()
    dic = dic.translate(str.maketrans(x+y, y+x))
print(S.translate(str.maketrans(string.ascii_lowercase, dic)))
