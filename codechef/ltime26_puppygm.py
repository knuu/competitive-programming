for _ in range(int(input())):
    A, B = map(int, input().split())
    print('Tuzik' if A % 2 == 0 or B % 2 == 0 else 'Vanka')
