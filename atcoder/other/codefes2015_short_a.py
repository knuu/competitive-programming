#a,b=int,input;N=a(b());s=list(map(a,b().split()));print('Pass'if 2*N*s[0]>sum(s)else'Fail')
#N=int(input());s=[int(input())for _ in range(N)];print('Pass'if 2*N*s[0]>sum(s)else'Fail')
#N=int(input());s=[int(input())for _ in range(N)];print(['Fail','Pass'][2*N*s[0]>sum(s)])
#int,input=a,b;N=a(b());s=[a(b())for _ in range(N)];print('Pass'if 2*N*s[0]>sum(s)else'Fail')
#int,input=a,b;s=[a(b())for _ in range(a(b()))];print(['Pass','Fail'][2*len(s)*s[0]>sum(s)]
#a=input;N=a();s=[a()for _ in range(N)];print(['Fail','Pass'][2*N*s[0]>sum(s)])
N=input();s=[input()for _ in[0]*N]
print'Pass'*(2*N*s[0]>sum(s))or'Fail'
