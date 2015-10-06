// for poj (old g++ version, cannot use bits/stdc++.h)

#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm>
#include <complex>
#include <string>
#include <utility>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef pair<int, P> T;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

#define MAX_N 500010

int parent[MAX_N];
int ufrank[MAX_N];

struct DisjointSet {

  DisjointSet(int N) {
    for (int i = 0; i < N; i++) {
      parent[i] = i;
      ufrank[i] = 0;
    }
  }

  int find(int x) {
    if (parent[x] == x) {
      return x;
    } else {
      return parent[x] = find(parent[x]);
    }
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return ;

    if (ufrank[x] < ufrank[y]) {
      parent[x] = y;
    } else {
      parent[y] = x;
      if (ufrank[x] == ufrank[y]) ufrank[x]++;
    }
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }
      
};


int main() {

  int N, K;
  scanf("%d %d", &N, &K);

  DisjointSet uf(3*N);

  int ans = 0;
  REP(i, K) {
    int t, x, y;
    scanf("%d %d %d", &t, &x, &y);
    x--, y--;
    if (x < 0 || N <= x || y < 0 || N <= y) {
      ans++;
    } else if (t == 1) {
      if (uf.same(x, y + N) || uf.same(x, y + 2*N)) {
	ans++;
      } else {
	uf.unite(x, y);
	uf.unite(x + N, y + N);
	uf.unite(x + 2*N, y + 2*N);
      }
    } else if (t == 2) {
      if (uf.same(x, y) || uf.same(x, y + 2*N)) {
	ans++;
      } else {
	uf.unite(x, y + N);
	uf.unite(x + N, y + 2*N);
	uf.unite(x + 2*N, y);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
