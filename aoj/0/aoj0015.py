for _ in range(int(input())):
    a=int(input())+int(input())
    print(a if a<10**80 else 'overflow')
