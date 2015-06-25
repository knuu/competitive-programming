from math import sqrt
def main():
    n = int(input())

    n = n * (n+1) // 2

    if n == 1:
        print('BOWWOW')
        return 

    for i in range(2, int(sqrt(n))+2):
        if n % i == 0:
            print('BOWWOW')
            return
    print('WANWAN')

if __name__ == '__main__':
    main()
    
