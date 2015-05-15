def cprint(c):
    r, i = c.real, c.imag
    if r != 0:
        if i > 0:
            print('{:.2f} + {:.2f}i'.format(r, i))
        elif i < 0:
            print('{:.2f} - {:.2f}i'.format(r, abs(i)))
        else:
            print('{:.2f}'.format(r))
    else:
        if i != 0:
            print('{:.2f}i'.format(i))
        else:
            print('{:.2f}'.format(0))
                
            
cr, ci = map(float, input().split())
dr, di = map(float, input().split())
c = complex(cr, ci)
d = complex(dr, di)
cprint(c+d)
cprint(c-d)
cprint(c*d)
cprint(c/d)
print('{0:.2f}'.format(abs(c)))
print('{0:.2f}'.format(abs(d)))
    
