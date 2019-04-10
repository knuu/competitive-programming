#d=lambda a:max([(a%i<1)*d(a/i)for i in range(2,a+1)]+[0])+sum(map(int,`a`));print(d(input()))
#d=lambda a:max([a%i<1and d(i)for i in range(1,a)]+[0])+sum(map(int,`a`));print d(input())
d=lambda a:max([d(i)for i in range(1,a)if a%i<1]+[0])+sum(map(int,`a`));print d(input())
"""
def d(a):
    ret = []
    for i in range(2, a+1):
        if a % i == 0:
            c = d(a/i)
            if sum(map(int,''.join(map(str,c)))) > sum(map(int,''.join(map(str,ret)))):
                ret = c
    return ret+[a]
for i in range(1,101):
    r = d(i)
    print i,sum(map(int,''.join(map(str,r)))),r
"""             
