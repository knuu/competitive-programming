//
//  AOJ0516.cpp
//  
//
//  Created by knuu on 2014/06/11.
//
//

#include <iostream>

using namespace std;

int main()
{
	int k,n;
	int a[100000];
	while (cin>>n>>k,n!=0&&k!=0) {
		long long sum=0,max;
		for (int i=0; i<k; i++) {
			cin>>a[i];
			sum+=a[i];
		}
		max=sum;
		for (int i=k; i<n; i++) cin>>a[i];
		for (int i=k; i<n; i++) {
			sum=sum+a[i]-a[i-k];
			max=max(max,sum);
		}
		cout<<max<<endl;
	}
}
