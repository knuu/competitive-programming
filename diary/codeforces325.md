http://codeforces.com/contest/586
# div2 A. Alena's Schedule

- タグ: シミュレーション
- レベル: 1

# div2 B. Laurenty and Shop

- 解法
    - 累積和で上下の道それぞれについて(それぞれrow[0], row[1]とする)、家の間の距離を求めておき、row\[0\]\[i\] + cross[i] + (row\[1\]\[i\] - row\[1\]\[N-1\]を求めてソートして最初の2つを足す。O(NlogN)
    - 深さ優先探索する。O(N^2)
- タグ: 累積和、全探索
- レベル: 2

# div2 C. Gennady the Dentist

- タグ: シミュレーション、キュー
- レベル: 2
