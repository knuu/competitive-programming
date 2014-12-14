def check(p):
    while True:
        l=len(p)
        if l==0 or l==1: return l-1
        if '()' in p: p = p.replace('()','')
        elif '[]' in p: p = p.replace('[]','')
        else: return False
while True:
    s=input()
    if s=='.':break
    p = ''.join([c for c in s if c in '()[]'])
    print('yes' if check(p) else 'no')
