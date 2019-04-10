#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
//typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int main() {
  int N; scanf("%d", &N);
  int root; scanf("%d", &root);
  const int INF = 1 + 1e9;
  set<pair<int, int>> leaf; // val, parent
  vector<int> ans;
  leaf.insert(make_pair(root, root));
  leaf.insert(make_pair(INF, root));

  REP(_, N-1) {
    int a; scanf("%d", &a);
    auto lb = leaf.lower_bound(make_pair(a, 0));
    ans.push_back(lb->second);
    int v = lb->first;
    leaf.erase(lb);
    leaf.insert(make_pair(v, a));
    leaf.insert(make_pair(a, a));
  }
  REP(i, N-1) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");

  return 0;
}
