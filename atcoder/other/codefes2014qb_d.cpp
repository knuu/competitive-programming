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

#define INF (int)1e6

int leftdp[100010], rightdp[100010];
int height[100010];

int main() {
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  height[0] = height[N+1] = INF;
  REP(i, N) cin >> height[i+1];

  for (int i = N; i > 0; i--) {
    int r = i+1;
    while (height[i] >= height[r]) r = rightdp[r];
    rightdp[i] = r;
  }

  FOR(i, 1, N+1) {
    int l = i-1;
    while (height[i] >= height[l]) l = leftdp[l];
    leftdp[i] = l;
  }

  FOR(i, 1, N+1) {
    cout << (rightdp[i] - i - 1) + (i - leftdp[i] - 1) << endl;
  }
  return 0;
}
