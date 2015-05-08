for i in range(int(input())):print('Fizz'*((i%3+1)//3)+'Buzz'*((i%5+1)//5)+str(i+1)*(not(((i%3+1)//3)or((i%5+1)//5))))
