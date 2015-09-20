#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define MP make_pair
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define fst first
#define snd second

int score[100010];

int main() {
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  REP(i, N) cin >> score[i+1];
  score[0] = 0;
  sort(score, score+N+1);

  int zero = upper_bound(score, score+N+1, 0) - score - 1;
  int Q;
  cin >> Q;
  REP(i, Q) {
    int k;
    cin >> k;
    if (k == N || N-k <= zero) {
      cout << 0 << endl;
    } else if (k == 0) {
      cout << score[N] + 1 << endl;
    } else {
      cout << (score[N-k+1] == score[N-k] ? score[N-k+1] + 1 : score[N-k]+1) << endl;
    }
  }
      
  return 0;
}
