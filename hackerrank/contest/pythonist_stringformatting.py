N = int(input())
width = len(format(N, 'b'))
for num in range(1,N+1): 
    for base in 'doXb':
        print('{0:{width}{base}}'.format(num, base=base, width=width), end=' ')
    print()
