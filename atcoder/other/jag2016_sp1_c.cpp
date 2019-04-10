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


string union_tree(string A, string B) {
  if (A == "()" or B == "()") {
    return "()";
  }
  vector<string> S{A, B};
  vector<int> cnt(2, 0), num(2, 0);
  vector<string> left(2), right(2);
  REP(i, 2) {
    REP(j, S[i].size()) {
      if (S[i][j] == '(') {
        cnt[i]++;
      } else if (S[i][j] == ')') {
        cnt[i]--;
      } else if (S[i][j] == '[' and cnt[i] == 1) {
        left[i] = S[i].substr(1, j - 1);
        j++;
        while (S[i][j] != ']') {
          num[i] = num[i] * 10 + (S[i][j] - '0');
          j++;
        }
        right[i] = S[i].substr(j+1, S[i].size()-1-j-1);
        break;
      }
    }
  }
  return "(" + union_tree(left[0], left[1]) + "[" + to_string(num[0] + num[1]) + "]" + union_tree(right[0], right[1]) + ")";
}


int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  string A, B; cin >> A >> B;
  A = "(" + A + ")";
  B = "(" + B + ")";
  string ans = union_tree(A, B);
  cout << ans.substr(1, ans.size() - 2) << endl;
  return 0;
}
