I=lambda:map(int,raw_input().split());N,Q=I();p,r,f=range(N+1),[0]*(N+1),lambda x:(p[x]==x)*x or f(p[x])
def u(x, y):
 x,y=f(x),f(y)
 if x==y:return
 if r[x]<r[y]:p[x]=y
 else:
  p[y] = x
  if r[x]==r[y]:r[x]+=1
for a,b,c in[I()for _ in[0]*Q]:
 k=[u,lambda x,y:['NO','YES'][f(x)==f(y)]][a](b,c)
 if a: print k
