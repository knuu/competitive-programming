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
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

int perm[100010];
bool used[100010];

int main() {
  int N;
  scanf("%d", &N);
  REP(i, N) {
    scanf("%d", perm+i);
    perm[i]--;
  }

  fill(used, used+N, false);
  bool cnt1 = false, cnt2 = false;
  int cy1;
  P cy2;
  REP(i, N) {
    if (!used[i]) {
      int cnt = 0, next = i;
      while (!used[next]) {
	used[next] = true;
	next = perm[next];
	cnt++;
      }
      if (cnt == 1) {
	cnt1 = true;
	cy1 = i;
      }
      if (cnt == 2) {
	cnt2 = true;
	cy2 = make_pair(i, perm[i]);
      }
    }
  }

  if (cnt1) {
    printf("YES\n");
    used[cy1] = true;
    REP(i, N) {
      if (i != cy1) {
	printf("%d %d\n", cy1+1, i+1);
      }
    }
  } else if (cnt2) {
    vector<P> ans;
    used[cy2.first] = used[cy2.second] = true;
    ans.push_back(P(cy2.first+1, cy2.second+1));
    fill(used, used+N, 0);
    REP(i, N) {
      if (i != cy2.first && i != cy2.second && !used[i]) {
	int cnt = 0, next = i;
	while (!used[next]) {
	  ans.push_back(P(next+1, (cnt % 2 == 0 ? cy2.first : cy2.second)+1));
	  used[next] = true;
	  next = perm[next];
	  cnt++;
	}
	if (cnt % 2) {
	  printf("NO\n");
	  return 0;
	}
      }
    }
    printf("YES\n");
    for (P p : ans) {
      printf("%d %d\n", p.first, p.second);
    }
  } else {
    printf("NO\n");
  }
  return 0;
}
