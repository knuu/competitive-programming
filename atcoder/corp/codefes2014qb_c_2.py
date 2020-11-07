from collections import Counter as C
i,s=lambda:C(input()),lambda t:sum(t.values());a,b,c=i(),i(),i();a,b,N=a&c,b&c,s(c);print('NO'if any((a+b)[k]<v for k,v in c.items())|(s(a)*2<N)|(s(b)*2<N)else'YES')
