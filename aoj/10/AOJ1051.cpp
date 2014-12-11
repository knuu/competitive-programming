//
//  AOJ1051.cpp
//  
//
//  Created by knuu on 2014/06/11.
//
//

#include <iostream>

using namespace std;

int main()
{
	int N,now,prev,page[50];
	while (cin>>N,N) {
		prev=0;
		for (int i=0; i<N; i++) cin>>page[i];
		for (int i=0; i<N; i++) {
			if (i&&i-N+1) {
				if (page[i-1]+1==page[i]&&page[i]+1!=page[i+1]) {
					cout<<'-'<<page[i];
				} else if (page[i-1]+1!=page[i]&&page[i]+1==page[i+1]) {
					cout<<' '<<page[i];
				} else if (page[i-1]+1!=page[i]&&page[i]+1!=page[i+1]) {
					cout<<' '<<page[i];
				}
			} else if (i==0) {
				cout<<page[0];
			} else {
				if (page[i-1]+1==page[i]) {
					cout<<'-'<<page[i];
				} else {
					cout<<' '<<page[i];
				}
			}
		}
		cout<<endl;
	}
}
