input(); print(*filter(lambda x: x, map(lambda x:x.lower().translate(str.maketrans('bcdwtjfqlvsxpmhkngzr', '11223344556677889900', 'aeiouy,.')), input().split())))
