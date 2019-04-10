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
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

int L[10010];

struct SegmentTree {
  int N, _N;
  double vx[10010], vy[10010], ang[10010];

  SegmentTree(int _N) : _N(_N) {
    assert(_N > 0);
    N = 1;
    while (N < _N)
      N <<= 1;
    init(0, 0, _N);
  }

  double init(int k, int l, int r) {
    vx[k] = ang[k] = 0.0;
    if (r - l == 1) {
      vy[k] = L[l];
    } else {
      int chl = 2*k+1, chr = 2*k+2, mid = (l+r)/2;
      vy[k] = init(chl, l, mid) + init(chr, mid, r);
    }
    return vy[k];
  }    

  void update(int s, double a) {
    update(s, a, 0, 0, _N);
  }
  
  void update(int s, double a, int v, int l, int r) {
    if (s <= l) {
      return ;
    } else if (s < r) {
      int chl = 2*v+1, chr = 2*v+2, mid = (l+r)/2;
      update(s, a, chl, l, mid);
      update(s, a, chr, mid, r);
      if (s <= mid) ang[v] += a;

      double s = sin(ang[v]), c = cos(ang[v]);
      vx[v] = vx[chl] + (c * vx[chr] - s * vy[chr]);
      vy[v] = vy[chl] + (s * vx[chr] + c * vy[chr]);
    }
  }
  pair<double, double> query(int a) {
    return make_pair(vx[a], vy[a]);
  }
};

double prv[10010];

int main() {
  int cnt = 0;
  while (true) {
    int N, C;
    if (cin >> N >> C) {
      if (cnt++) printf("\n");
    } else {
      break;
    }

    REP(i, N) scanf("%d", L+i);
    
    SegmentTree sgt(N);
    REP(i, N) prv[i] = acos(-1);
    prv[0] = 0.0;

    REP(i, C) {
      int s;
      double a;
      cin >> s >> a;
      a = a / 360.0 * acos(-1) * 2;

      sgt.update(s, a - prv[s]);
      prv[s] = a;

      pair<double, double> p = sgt.query(0);
      printf("%.2f %.2f\n", p.first, p.second);
    }
  }
    
  return 0;
}
