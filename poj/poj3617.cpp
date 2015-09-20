#include <iostream>

using namespace std;

#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)

char S[2048];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  REP(i, N) cin >> S[i];

  char T[2048];
  int left = 0, right = N-1;
  REP(i, N) {
    if (S[left] < S[right]) {
      T[i] = S[left];
      left++;
    } else if (S[left] > S[right]) {
      T[i] = S[right];
      right--;
    } else {
      int l = left, r = right;
      while (l < right && S[l] == S[r]) l++, r--;
      if (S[l] <= S[r]) {
	T[i] = S[left];
	left++;
      } else {
	T[i] = S[right];
	right--;
      }
    }
  }
  REP(i, N) {
    cout << T[i];
    if (i == N-1 || (i+1) % 80 == 0) cout << endl;
  }
  return 0;
}
