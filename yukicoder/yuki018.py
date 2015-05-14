import string
def decode(c, i):
    return string.ascii_uppercase[(ord(c)-ord('A')-i)%26]
S = input()
print(''.join([decode(s, i+1) for i, s in enumerate(S)]))
