http://codeforces.com/contest/588
# div2 A. Duff and Meat

- タグ: シミュレーション
- レベル: 1

# div2 B. Duff in Love

- 問題
    - N(10^12以下)の約数のうち、任意の1より大きい整数aについて、a^2で割り切れない最大の約数を求めよ
- 解法
    1. 素因数の集合の要素の積を求めれば良い。素因数分解と同じ手順で求められるので、O(sqrt(N))
    2. 約数を求める手順でも求められる。O(sqrt(N))
- タグ: 数学、素因数分解、約数
- レベル: 2

# div1 A. Duff and Weight Lifting

- 問題
    - 2^w(wは10^6以下)の数がN個(10^6以下)ある。sum(2^a1 + ... + 2^an)もまた2の累乗となるように、できるだけ多くの数を組み合わせたとき、最小何個にすることができるか
- 解法
    - 2^w + 2^w = 2^(w+1)を利用する。つまり、2^wがk個あれば、2^(w+1)がk/2個作れ、2^wがk%2個余る。これをw=0からw=10^6+log(10^6)くらいまで求めていき、k%2の和が答えである。O(N+max(w))
- タグ: 数学、2進数、貪欲法
- レベル: 2