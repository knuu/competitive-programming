n = input()
lenN = len(n)
candiv8s = [str(x) for x in range(0, 1000, 8)]
def isPart(s1, s2):
    i = 0
    lenS2 = len(s2)
    for s in s1:
        while i < lenS2:
            if s2[i] == s:
                i += 1
                break
            i += 1
        else:
            return False
    return True
for candiv8 in candiv8s:
    if isPart(candiv8, n):
        print('YES')
        print(candiv8)
        exit(0)
print('NO')
