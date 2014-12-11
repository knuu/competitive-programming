//
//  AOJ0555.cpp
//  
//
//  Created by knuu on 2014/06/11.
//
//

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int N,ans=0;
	char s[11],ring[11];
	cin>>s>>N;
	for (int i=0; i<N; i++) {
		cin>>ring;
		for (int j=0; j<strlen(ring); j++) {
			int k;
			for (k=0; k<strlen(s); k++) {
				if (s[k]!=ring[(j+k)%strlen(ring)]) break;
			}
			if (k==strlen(s)) {
				ans++;
				break;
			}
		}
	}
	cout<<ans<<endl;
}
