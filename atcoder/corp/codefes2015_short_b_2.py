I=lambda:map(int,input().split());N,Q=I();p,r,f=list(range(N+1)),[0]*(N+1),lambda x:x*(p[x]==x)or f(p[x])
def u(x,y):p[x]=y
def w(x,y):p[y]=x;r[x]+=r[x]==r[y]
for a,b,c in[I()for _ in[0]*Q]:[[w,u][r[f(b)]<r[f(c)]],lambda x,y:print(['NO','YES'][f(x)==f(y)])][a](f(b),f(c))
