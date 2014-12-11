//
//  AOJ0278.cpp
//  
//
//  Created by knuu on 2014/05/28.
//
//

#include <iostream>

using namespace std;

void solve();
int N,x,y,b,p;

int main()
{
	cin>>N;
	for (int i=0; i<N; i++) {
		cin>>x>>y>>b>>p;
		solve();
	}
}

void solve()
{
	int ans,c1=x*b+y*p,c2=0.8*(x*max(5,b)+y*max(2,p));
	ans=min(c1,c2);
	cout<<ans<<endl;
}
