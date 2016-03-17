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

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N; cin >> N;
  vector<T> people;
  REP(i, N) {
    string s;
    int b, e;
    cin >> s >> b >> e;
    people.push_back(T(b, 1, s == "M"));
    people.push_back(T(e+1, -1, s == "M"));
  }
  sort(ALL(people));
  int male = 0, female = 0, ans = 0;
  for (T t : people) {
    int time, flag, sex; tie(time, flag, sex) = t;
    //cout << male << ' ' << female << endl;
    //cout << time << ' ' << flag << ' ' << sex << endl;
    if (flag == 1) {
      (sex == 1 ? male : female)++;
      ans = max(ans, min(male, female)*2);
    } else {
      (sex == 1 ? male : female)--;
    }
  }
  cout << ans << endl;
  return 0;
}
