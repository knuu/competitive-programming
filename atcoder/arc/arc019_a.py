s = input()
print(s.translate(s.maketrans({'O': '0', 'D': '0', 'I': '1', 'Z': '2', 'S': '5', 'B': '8'})))
