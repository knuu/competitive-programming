N, S, T = map(int, input().split())
sb, tb = S.bit_length(), T.bit_length()
print(tb - sb if (T >> max(0, tb - sb)) == S else -1)
