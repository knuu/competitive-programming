//
//  ARC026-B.cpp
//  
//
//  Created by knuu on 2014/06/30.
//
//

#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	long long num,sum=1;
	cin>>num;
	if (num==1) {
		cout<<"Deficient"<<endl;
		return 0;
	}
	for (int i=2; i<sqrt(num); i++) {
		if (num%i==0) {
			sum+=i+num/i;
		}
	}
	if (sqrt(num)-(long long)sqrt(num)==0 && num % (long long)sqrt(num)==0) {
		sum+=sqrt(num);
	}
	if (sum==num) {
		cout<<"Perfect"<<endl;
	} else if (sum<num) {
		cout<<"Deficient"<<endl;
	} else {
		cout<<"Abundant"<<endl;
	}
}
