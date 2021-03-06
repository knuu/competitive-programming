# div2 A. Bear and Elections

- 問題
    - 要素数N($10^2$以下)の数列A(各要素は$10^3$以下)が与えられる。A[0]を最大にするためにA[1]からA[N-1]の数字を最小どれだけ移動させればよいか。
- 解法
    1. A[0]以外の要素を優先度付きキューに入れ、キューをpopするたびにA[0]の値に1を足していき、(popした数 - 1)を再び優先度付きキューにpushする。A[0]がpopした数より大きくなったら終了し、popした回数を出力する。最大 O(N\*max(A)\*log(N))
    2. 最大値を取り出すということに関しては、1と同じだが、A[1]からA[N-1]までの最大値を毎回探す。最大O(N\*max(A)\*N(今回はこれでも間に合う)
- 類題
    - Aの要素がもっと多くなったら(例えば$10^9$とか)どうか？
        - A[1]からA[N]を予め降順ソートしておいて、A[0]からA[i]までの平均$\ge$ A[i+1]となるiを求めて、その平均\*(i-1)+αくらいが答えになる気がする。O(NlogN)
- タグ: シミュレーション

# div2 B. Bear and Three Musketeers

- 問題
    - 頂点数N、枝数M(NとMはともに$4*10^3$以下)の無向グラフが与えられる。長さ3の閉路において、(閉路を構成する頂点の次数の和)-6 の最小値を出力せよ。
- 解法
    1. Brute force。各頂点の次数と隣接行列をもっておき、可能な組合せを全て試す。O(N^3)となり、今回だとTLE。
    2. 各頂点の次数と隣接する頂点集合を持っておき、各枝について、接続頂点ペアが、共通の隣接頂点を持っていないか探す。O(NMlog(M))
    3. 各頂点の次数と隣接行列を持っておき、各枝について、接続頂点ペアが、共通の隣接頂点を持っていないか探す。O(NM)
- 類題
    - 長さKの閉路だとどうか、K-クリークだとどうか。
        - 密なグラフだと、1でO(N^K)、疎なグラフだと2でO(NM^Klog(M))でいけそう？(後半は怪しい)
- タグ: グラフ、全探索

# div1 A. Bear and Poker

- 問題
    - 要素数N(10^5以下)の配列A(各要素は10^9以下)が与えられる。このとき、各要素ごとに2倍もしくは3倍を繰り返すことで、全ての要素を等しくできるか？
- 解法
    1. 各要素を素因数分解した場合を考える。2倍・3倍を繰り返しても変化するのは素因数2と3の指数だけである。よって、素因数2と3以外の素因数と指数は全ての要素で一致していなければいけない。従って、各要素を2と3で割れるだけ割って、各要素が一致するか調べれば良い。O(Nlog(max(A)))
    2. もし、Yesとなる場合は、1で述べた理由より、配列の全要素のgcdをとった値が、1において、一致するはずの値となるはずである。よってその値をgcd_allとおくと、(A[i]の素因数2と3の積) * gcd_all = A[i]が成立しなければいけない。これをシミュレーションすればよい。O(Nlog(max(A)))
- 類題
    - K > L かつ gcd(K, L) != 1 かつ K % L != 0であるようなK, Lをとって、K倍・L倍の場合はどうか(たとえば4倍と6倍)
        - 4倍と6倍だと、もとの数の素因数2と3の指数を考えて、その余りとかで判断すればよさそう？
- タグ: 数学

# div1 B. Bear and Blocks

- 問題
    - N個(10^5以下)のタワーTが1列に接して並んでおり、i番目のタワーはh\[i\]\(10^9以下\)個のブロックから成り立っている。毎ターン、上下左右がタワーもしくは床に接しているブロック以外を取り除く。何ターンで全てのブロックを取り除けるか？
- 解法
    - 毎ターンごとに、一番上のブロックと、横のブロックの高さ分だけブロックが取り除かれることを考えると、kターン終了後のi番目のタワーの高さはh[i] = min{h[j]-(k-j) | 0<=j<=N+1} である(ただし、h[0]=h[N+1]=0である)。よって、h[i]=0となるのはk=min{h[j]+j | 0<=j<=N+1} ターンであるので、各タワーの必要ターン数の最大値が答えである。愚直にやるとO(N^2)かかるが、h[i]=0となるをk=min((左側の最小ターン数)+1, h[i], (右側の最小ターン数)+1)と考えると、dpっぽく1からNまでとNから1までの両方を計算してやることで最大ターン数が求められる。O(N)
    - 二分探索でもいけるらしい？O(NlogN)
- 類題
    - あるブロックを選び、そのブロックと四方のブロックを取り除く場合の最小ターン数は？
        - わからん、4方向で壊せるだけ壊したあとにhoge？
- 知見
    - 両側DP(両側の最適値を取る場合、それぞれ片側で最適値を計算し、2つの最適値の最適値をとるといったDP。完全に造語)
- タグ: DP、両側DP
