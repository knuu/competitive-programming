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

int A[100010];

int main() {
  int N;
  set<int> a_set;
  cin >> N;
  REP(i, N) {
    scanf("%d\n", &A[i]);
    while (A[i] % 2 == 0) A[i] /= 2;
  }

  a_set.insert(A, A + N);
  cout << a_set.size() << endl;
  return 0;
}
