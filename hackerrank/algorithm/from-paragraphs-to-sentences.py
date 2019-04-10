def is_end(w):
    if w == "Dr.":
        return False
    elif len(w) == 2 and w[0].isupper():
        return False
    elif w[-1] in '.!?':
        return True
    else:
        return False

S = list(input())
for i, s in enumerate(S):
    if i < len(S)-1 and s in '.!?' and S[i+1].isupper():
        S[i] = s + ' '
S = ''.join(S).split()

for word in S:
    print(word, end='\n' if is_end(word) else ' ')
