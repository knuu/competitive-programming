ansOut = []
coin = [10, 50, 100, 500]
while True:
    price = int(input())
    if price == 0:
        break
    cash = list(map(int, input().split()))
    sumCash = sum(c * n for c, n in zip(coin, cash))
    change = sumCash - price
    changeCoins = [(change % 50) // 10, (change % 100) // 50, (change % 500) // 100, change // 500]

    out = []
    for i in range(4):
        if cash[i] > changeCoins[i]:
            out.append('{} {}'.format(coin[i], cash[i] - changeCoins[i]))
    ansOut.append('\n'.join(out))
print('\n\n'.join(ansOut))
    
