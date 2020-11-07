S = input()
for i in range(len(S)):
    tmp = S[i:]
    if tmp == tmp[::-1]:
        print(i)
        quit()
else:
    print(len(S))
