//
//  AOJ0544.cpp
//  
//
//  Created by knuu on 2014/06/11.
//
//

#include <iostream>

using namespace std;

int main()
{
	int N,M;
	int sugoroku[1000],saikoro[1000];
	while (cin>>N>>M,(N!=0&&M!=0)) {
		int pos=0,ans=0;
		for (int i=0; i<N; i++) cin>>sugoroku[i];
		for (int i=0; i<M; i++) cin>>saikoro[i];
		while (pos<N-1) {
			pos+=saikoro[ans];
			pos+=sugoroku[pos];
			ans++;
		}
		cout<<ans<<endl;
	}
}
