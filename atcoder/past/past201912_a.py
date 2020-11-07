S = input()
if any(not x.isdigit() for x in S):
    print("error")
else:
    print(int(S) * 2)
