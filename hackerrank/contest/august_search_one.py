def change(n):
    num = ['zero', 'one', 'two', 'three', 'four',
           'five', 'six', 'seven', 'eight', 'nine',
           'ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen',
           'sixteen', 'seventeen', 'eighteen', 'nineteen']
    ten = ['', '', 'twenty', 'thirty', 'forty',
           'fifty', 'sixty', 'seventy', 'eighty', 'ninety',
           'hundred']
    
    if n < 20:
        return num[n]
    elif n % 10 == 0:
        return ten[n//10]
    else:
        return ten[n//10] + num[n%10]
    
for _ in range(int(input())):
    X = int(input())
    print(change(X))
