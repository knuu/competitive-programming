R,L=raw_input,len;A,B,d=R(),R(),lambda S:(L(S)>L(B))&any(d(S[:i]+`sum(map(int,S[i:i+2]))%10`+S[i+2:])for i in range(L(S)-1))|(S==B)
print d(A)*'YES'or'NO'
