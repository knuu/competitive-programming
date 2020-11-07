A, B = map(int, input().split())
div4 = B//4 - (A-1)//4
div100 = B//100 - (A-1)//100
div400 = B//400 - (A-1)//400
print(div4-div100+div400)
