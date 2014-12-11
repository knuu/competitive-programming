//
//  ABC012-C.cpp
//  
//
//  Created by knuu on 2014/07/12.
//
//

#include <iostream>

using namespace std;
int main()
{
	int N;
	cin>>N;
	N=2025-N;
	for (int i=1; i<=9; i++) {
		for (int j=1; j<=9; j++) {
			if (i*j==N) {
				cout<<i<<" x "<<j<<endl;
			}
		}
	}
}
