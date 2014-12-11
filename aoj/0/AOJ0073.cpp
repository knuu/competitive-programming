//
//  AOJ0073.cpp
//  
//
//  Created by knuu on 2014/06/18.
//
//

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int x,h;
	double S;
	while (cin>>x>>h,x!=0&&h!=0) {
		S=x*x+2*x*sqrt(h*h+x*x/4.0);
		printf("%.6lf\n",S);
	}
}
