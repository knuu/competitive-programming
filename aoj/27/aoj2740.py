def parse_node(l, r, S):
    left, right = 0, 0
    cnt = 0
    for i in range(l, r + 1):
        if S[i] == '(':
            cnt += 1
        elif S[i] == ')':
            cnt -= 1
        elif cnt == 0 and S[i] == "[":
            left = i
        elif cnt == 0 and S[i] == "]":
            right = i
    return left, right


def parser(l1, r1, l2, r2):
    n1_l, n1_r = parse_node(l1, r1, S1)
    n2_l, n2_r = parse_node(l2, r2, S2)
    # print(n1_l, n1_r, n2_l, n2_r)
    node = "[{}]".format(int(S1[n1_l + 1:n1_r]) + int(S2[n2_l + 1:n2_r]))
    left_node = "({})".format("" if min(n1_l - l1, n2_l - l2) <= 2 else parser(l1 + 1, n1_l - 2, l2 + 1, n2_l - 2))
    right_node = "({})".format("" if min(r1 - n1_r, r2 - n2_r) <= 2 else parser(n1_r + 2, r1 - 1, n2_r + 2, r2 - 1))
    return left_node + node + right_node



S1, S2 = input(), input()
print(parser(0, len(S1) - 1, 0, len(S2) - 1))
