s = input()
p = input()

s += s[:len(p)]
if p in s:
    print("Yes")
else:
    print("No")

