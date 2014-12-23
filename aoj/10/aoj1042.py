while True:
    s = input()
    if s == 'END OF INPUT': break
    print(''.join(str(len(x)) for x in s.split(' ')))
