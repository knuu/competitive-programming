S = input()
c, f = S.find("C"), S.rfind("F")
print("Yes" if c != -1 and f != -1 and c < f else "No")
