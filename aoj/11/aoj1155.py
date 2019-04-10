def parser(left, right):
    if S[left] == '(' and S[right - 1] == ')':
        cnt = 0
        for i in range(left + 1, right - 1):
            if S[i] == '(':
                cnt += 1
            elif S[i] == ')':
                cnt -= 1
            elif cnt == 0 and S[i] == '+':
                return [max(x, y) for x, y in zip(parser(left + 1, i), parser(i + 1, right - 1))]
            elif cnt == 0 and S[i] == '*':
                return [min(x, y) for x, y in zip(parser(left + 1, i), parser(i + 1, right - 1))]
    elif S[left] == '-':
        return [2 - x for x in parser(left + 1, right)]
    elif S[left] == 'P':
        return [i // 9 % 3 for i in range(27)]
    elif S[left] == 'Q':
        return [i // 3 % 3 for i in range(27)]
    elif S[left] == 'R':
        return [i % 3 for i in range(27)]
    else:
        return [int(S[left]) for _ in range(27)]


while True:
    S = input()
    if S == '.':
        break
    print(parser(0, len(S)).count(2))
