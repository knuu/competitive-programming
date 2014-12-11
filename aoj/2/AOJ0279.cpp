//
//  AOJ0279.cpp
//  
//
//  Created by knuu on 2014/05/28.
//
//

#include <iostream>
#define MAX_N 10000

using namespace std;

int N;
int k[MAX_N];

//void solve();

int main()
{
	while (cin>>N&&N) {
		//for (int i=0; i<N; i++) cin>>k[i];
		//solve();
		int ans=N+1,t;
		bool check=false;
		for (int i=0; i<N; i++) {
			cin>>t;
			if (t==0) ans--;
			else if (t>1) check=true;
		}
		if (check) {
			cout<<ans<<endl;
		} else {
			cout<<"NA"<<endl;
		}
	}
}
/*
void solve()
{
	int zero=0;
	sort(k,k+N);
	if (k[N-1]<2) {
		cout<<"NA"<<endl;
	} else if (k[0]>=2) {
		cout<<N+1<<endl;
	} else {
		while (k[zero]==0) zero++;
		cout<<N+1-zero<<endl;
	}
	
}
*/
