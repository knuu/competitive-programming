//
//  ALDS1-11-B.cpp
//  
//
//  Created by knuu on 2014/06/03.
//
//

#include <iostream>

using namespace std;

int d[100]={0},f[100]={0};
int k[101],v[101][100],n;
int c;
void solve();
void dfs(int point);

int main()
{
	cin>>n;
	for (int i=0; i<n; i++) {
		int t;
		cin>>t;
		cin>>k[t];
		for (int j=0; j<k[t]; j++) {
			cin>>v[t][j];
		}
	}
	solve();
}

void solve() {
	d[1]=1,c=2;
	for (int i=0; i<k[1]; i++) {
		if (d[v[1][i]]==0) {
			dfs(v[1][i]);
		}
	}
	c++;
	f[1]=c;
	for (int i=0; i<n; i++) {
		cout<<i+1<<' '<<d[i+1]<<' '<<f[i+1]<<endl;
	}
}
void dfs(int point)
{
	d[point]=c;
	int i=0;
	c++;
	while (i<k[point]) {
		if (d[v[point][i]]==0) {
			dfs(v[point][i]);
			c++;
		}
		i++;
	}
	if (f[point]==0) {
		f[point]=c;
	}
}
