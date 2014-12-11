//
//  AOJ0270.cpp
//  
//
//  Created by knuu on 2014/06/11.
//
//

#include <iostream>

#define max(x,y) (x)>(y) ? (x) : (y)

using namespace std;

int main()
{
	int N,Q,c[300001]={0},m=0,q,t;
	cin>>N>>Q;
	for (int i=0; i<N; i++) {
		cin>>t;
		c[t]=1;
		m=max(m,t);
	}
	
	for (int i=0; i<Q; i++) {
		cin>>q;
		if (q>m) {
			cout<<m<<endl;
			continue;
		}
		bool flag=false;
		for (int j=q-1; j>=0; j--) {
			for (int k=0; k+j<=300000; k+=q) {
				if (c[k+j]==1&&(k!=0||j!=0)) {
					flag=true;
					break;
				}
			}
			if (flag) {
				cout<<j<<endl;
				break;
			}
		}
	}
}