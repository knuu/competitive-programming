http://codeforces.com/contest/598

# A. Tricky Sum

- 問題
    - 1〜Nまでの数について、i=2^kとなるiについては引き、それ以外については足したときの合計を求めよ。
- 解法
    - 1〜Nまでの和を求めて、2^kとなるものについては2回ずつ引く。O(t log n)
- 感想
    - long longを落とそうとしていた？
- タグ: 算数
- レベル: 1

# B. Queries on a String

- 問題
    - 文字列s(長さは10^4以下)が与えられ、Q(3\*10^2以下)回クエリが与えられる。各クエリは(l,r,k)の形であり、これは、文字列sの[l, r]をk回右にrotateせよ、という意味である。Q個のクエリを順に処理した後の文字列を出力せよ。
- 解法
    - j in [l,r]について、k回rotateした後の位置は(j-l+k)%(r-l+1)+lであり、j not in [l,r]については、位置は不変である。今回はクエリが少ないので、各クエリについて、これを求めてやればよい。O(Q|s|)
- 感想
    - 色々勘違いしていて、なかなか通らなかった
    - ちゃんと紙に書いてみることは大事
- タグ: 文字列、シミュレーション
- レベル: 2

# D. Igor In the Museum

- 問題
    - N\*M個(各10^3以下)のセルを持つ平面上が与えられ、壁で囲まれた部屋が与えられる。k回(min(nm, 10^5)以下)ある部屋の位置が与えられたとき、その部屋といくつの壁が接するかそれぞれ答えよ。
- 解法
    - 各地点について、dfsなりbfsでその部屋の番号と、壁と何個接しているかを予め求めておけばよい。O(NM+k)
- 感想
    - 部屋が何個あるかをちゃんと考えていなくてダメだった
- タグ: BFS
- レベル: 2
