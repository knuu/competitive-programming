s = input()
if len(s) == 1 or s[1:].isupper():
    print(s.swapcase())
else:
    print(s)
    
