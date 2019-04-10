print(max(map(len, ''.join(x if x == '…' else '_' for x in input()).split('_'))))
