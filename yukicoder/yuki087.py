N = int(input())

def isLeap(year):
    if (year % 4 == 0 and year % 100 != 0) or year % 400 == 0:
        return True
    else:
        return False
leap400 = 0
leap400List = []
y = 0
for i in range(2015, 2415):
    if isLeap(i):
        y += 366
    else:
        y += 365
    if y % 7 == 0:
        leap400 += 1
    leap400List.append(leap400)
print(leap400 * ((N-2014) // 400) + leap400List[(N-2014)%400-1])

