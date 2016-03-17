# 3468 A Simple Problem with Integers

- 問題
    - N要素を持つ数列Aが与えられる。これに対してQ個の、「A_a + ... + A_bの値を求めよ」と「A_a, ..., A_bのそれぞれにxを加えよ」のどちらかのクエリが与えられるので処理せよ。
- 解法
    - Segment Treeでrange addを実現する。蟻本の通り、Segment Treeを二つもって、一様に足された場合と、一様でなく足された場合を持っておけば良い。
    - 各クエリに対してO(logN)なので、初期化も含めると、O((N+Q)logN)
- レベル: 3
- タグ: Segment Tree、range add
- 感想
    - 頭良い
    - Fenwick Treeを二つ使うパターンもあるけどよく分からなかった
