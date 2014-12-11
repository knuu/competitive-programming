//
//  AOJ0577.cpp
//  
//
//  Created by knuu on 2014/06/11.
//
//

#include <iostream>

using namespace std;

int main()
{
	int N;
	int num[200][3],c[101],score[200]={0};
	cin>>N;
	for (int i=0; i<N; i++) cin>>num[i][0]>>num[i][1]>>num[i][2];
	for (int i=0; i<3; i++) {
		for (int j=1; j<=100; j++) c[j]=0;
		for (int j=0; j<N; j++) c[num[j][i]]++;
		for (int j=0; j<N; j++) {
			if (c[num[j][i]]==1) score[j]+=num[j][i];
		}
	}
	for (int i=0; i<N; i++) {
		cout<<score[i]<<endl;
	}
}
