def discard(c, cards):
    for card in cards:
        if c < card:
            return card
    return 0

while True:
    n = int(input())
    if n == 0: 
        break
    taro = [int(input()) for _ in range(n)]
    hanako = [x + 1 for x in range(2*n) if (x + 1) not in taro]
    taro.sort()
    hanako.sort()

    table = 0
    while True:
        if taro:
            table = discard(table, taro)
            if table:
                taro.remove(table)
            
        if not taro:
            print(len(hanako))
            print(0)
            break
        
        if hanako:
            table = discard(table, hanako)
            if table:
                hanako.remove(table)
        if not hanako:
            print(0)
            print(len(taro))
            break


