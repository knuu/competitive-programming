http://codeforces.com/contest/624

# div2 A. Save Luke

- 問題
    - 幅Lの棒の両端から、速さv1,v2で中央に向かう点がある。幅dの物体を棒のどこかに配置する。どちらの点もできるだけdに触れないような位置にdを配置したとき、最大何秒、点は物体に触れないか？
- 解法
    - t秒とすると、v1\*t = L - (v2\*t + d)が成り立つ。O(1)
    - 二分探索とかでもOK
- レベル: 1
- タグ: 算数

# div2 B. Making a String

- 問題
    - N(26以下)種類の文字がA_i個(10^9以下)ずつ用意されている。各文字種を使った回数が同じにならないような文字列を作るとき、最大どれだけの長さの文字列を作ることが出来るか？
- 解法
    - 個数でソートしておいて、大きい方からA_i個使えるか？A_i - 1使えるか？と順に調べていく。
    - 使えるかどうかにset型を使う場合、O(N^2 logN)
- レベル: 2
- タグ: シミュレーション、貪欲
- 類題
    - 文字の種類が多い場合はどうか？
        - ソートしておいて、大きい方から二分探索する。O(N log^2 N)

# div1 A. Graph and String

- 問題
    - abcの三種類からなる文字列sとグラフを「頂点iとjに枝があるための必要十分条件は、(s_i,s_j)!=(a,c)かつ(s_i, s_j)!=(c,a)が成立することである」として対応させるとする。グラフが与えられたとき、条件を満たす文字列は存在するか？
- 解法
    1. s_iがbであるならば、頂点iは全ての頂点と隣接している。逆は成り立たないが、s_iが全ての頂点と隣接しているならば、s_i=bとしても文字列が存在するかどうかは変わらない。よって、隣接行列の各行を調べて、他の全ての頂点と隣接している頂点をbとする。次に、まだ割り当てが決まっていない頂点を見つけて、それをaとする。その頂点と隣接している頂点のうち、割り当てが決まっていない頂点a、隣接していない頂点をcとする。最後に、もとのグラフと作成した文字列が対応しているかを調べればよい。O(|s|^2)
    2. bを指定するところまでは同じで、そこからbとなる頂点をグラフから取り除いたときに、連結成分が2個以下でかつ、連結成分が完全グラフならばよい。O(|s|^2)
- レベル: 2
- タグ: 文字列、グラフ
