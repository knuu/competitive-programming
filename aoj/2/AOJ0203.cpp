//
//  AOJ0203.cpp
//  
//
//  Created by knuu on 2014/06/24.
//
//

#include <iostream>

#define MAX_N 15

using namespace std;

int map[MAX_N+1][MAX_N+1];
int dp[MAX_N+2][MAX_N+2];
int X, Y;
int ans;

void solve();

int main()
{
	while (cin>>X>>Y, X != 0 && Y != 0) {
		for (int i = 1; i <= Y; i++) {
			for (int j = 1; j <= X; j++) {
				cin>>map[j][i];
				dp[j][i] = 0;
			}
		}
		solve();
	}
	
}

void solve()
{
	for (int i = 1; i <= Y ; i++) {
		for (int  j = 1; j <= X; j++) {
			if (i == 1) {
				map[j][i] == 1 ? dp[j][i] = 0 : dp[j][i] = 1;
			} else {
				switch (map[j][i]) {
					case 0:
						if (map[j-1][i-1] != 2) {
							dp[j][i] += dp[j-1][i-1];
						}
						if (map[j][i-1] != 2) {
							dp[j][i] += dp[j][i-1];
						}
						if (map[j+1][i-1] != 2) {
							dp[j][i] += dp[j+1][i-1];
						}
						if (map[j][i-2] == 2) {
							dp[j][i] += dp[j][i-2];
						}
						break;
						
					case 1:
						dp[j][i] = 0;
						break;
						
					case 2:
						if (map[j][i-1] != 2) {
							dp[j][i] += dp[j][i-1];
						}
						if (map[j][i-2] == 2) {
							dp[j][i] += dp[j][i-2];
						}
						break;
						
					default:
						break;
				}
			}
			
		}
	}
	int ans = 0;
	for (int i = 1; i <= X; i++) {
		ans += dp[i][Y];
		if (map[i][Y-1] == 2) ans += dp[i][Y-1];
	}
	cout<<ans<<endl;
}
