import string
rule = str.maketrans(''.join(input().split()), string.digits)
print(*sorted([input() for x in range(int(input()))], key=lambda x:int(x.translate(rule))), sep='\n')
