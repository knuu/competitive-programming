y, m, d = map(int, input().split('/'))

def isUruu(year):
    if year % 400 == 0 or (year % 4 == 0 and year % 100 != 0):
        return True
    else:
        return False

def isLastOfMonth(d, m, y):
    last_day = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    last_day_uruu = last_day[:]
    last_day_uruu[2] = 29

    if isUruu(y):
        return d == last_day_uruu[m]
    else:
        return d == last_day[m]

while y % (m * d) != 0:
    if m == 12 and d == 31:
        y += 1; m = 1; d = 1
    elif isLastOfMonth(d, m, y):
        m += 1; d = 1
    else:
        d += 1

print('{}/{}/{}'.format(str(y).zfill(4), str(m).zfill(2), str(d).zfill(2)))
