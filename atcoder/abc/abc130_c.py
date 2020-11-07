W, H, x, y = map(int, input().split())
is_mid_x = W % 2 == 0 and W // 2 == x
is_mid_y = H % 2 == 0 and H // 2 == y
print(H * W / 2, 1 if is_mid_y and is_mid_x else 0)
