def calc(y, m, d):
    if m == 1 or m == 2:
        y -= 1
        m += 12
    return 365 * y + y//4 - y //100 + y // 400 + 306 * (m + 1) // 10 + d - 429

day1 = [2014, 5, 17]
day2 = [int(input()) for _ in range(3)]
print(calc(*day1) - calc(*day2))
