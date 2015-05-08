N = int(input())
A = list(map(int, input().split()))
if N % 2 == 1:
    print('Iori' if sum(A) % 2 == 1 else 'Yayoi')
else:
    print('Iori' if min(A) % 2 == 1 or sum(A) % 2 == 1 else 'Yayoi')
