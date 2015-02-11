n, m, a = map(int, input().split())
height, width = n//a, m//a
if n % a != 0: height += 1
if m % a != 0: width += 1

print(height * width)
    
