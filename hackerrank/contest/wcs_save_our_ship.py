S = input()
sos = 'SOS' * (len(S) // 3)
print(sum(s1 != s2 for s1, s2 in zip(S, sos)))
