N = int(input())
if N % 2 == 0:
    print('1'*(N//2))
else:
    print('7'+'1'*((N-3)//2))
