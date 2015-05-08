Sa, Pa, Xa = input().split()
Sb, Pb, Xb = input().split()
Pa = int(Pa)
Pb = int(Pb)
if Pa > Pb:
    print(Sa)
elif Pa < Pb:
    print(Sb)
else:
    print(-1)
    
