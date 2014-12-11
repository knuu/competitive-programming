//
//  AOJ0062.cpp
//  
//
//  Created by knuu on 2014/06/18.
//
//

#include <iostream>

using namespace std;

int main()
{
	int sum,pascal[10]={1,9,36,84,126,126,84,36,9,1};
	double t;
	char input[11];
	while (cin>>input) {
		sum=0;
		for (int i=0; i<10; i++) sum+=(input[i]-'0')*pascal[i];
		cout<<sum%10<<endl;
	}
}
