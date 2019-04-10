sent = input().split()
x = int(sent[0])

if sent[-1] == 'week':
    if x in [5, 6]:
        print(53)
    else:
        print(52)
else:
    if x == 31:
        print(7)
    elif x == 30:
        print(11)
    else:
        print(12)
