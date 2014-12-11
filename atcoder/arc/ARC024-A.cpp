//
//  ARC024-A.cpp
//  
//
//  Created by knuu on 2014/05/31.
//
//

#include <iostream>
#include <algorithm>

using namespace std;
void solve();
int  L,R;
int l[100],r[100];
int main()
{
	cin>>L>>R;
	
	for (int i=0; i<L; i++) {
		cin>>l[i];
	}
	for (int i=0; i<R; i++) {
		cin>>r[i];
	}
	solve();
}

void solve()
{
	sort(l,l+L);
	int count=0;
	for (int i=0; i<R; i++) {
		if (binary_search(l,l+L,r[i])) {
			count++;
		}
	}
	cout<<count<<endl;
}