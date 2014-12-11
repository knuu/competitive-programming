//
//  AOJ0138.c
//
//
//  Created by n_knuu on 2014/04/05.
//
//

#include <stdio.h>
int main(void) {
    int first,second,third,fourth,i,j,num;
    double one,two,three=100000001.0,four=100000002.0,time1;
    for (i=0; i<3; i++) {
    	one=100000000.0,two=100000000.0;
        for (j=0; j<8; j++) {
            scanf("%d %lf",&num,&time1);
            if (time1<one) {
                if (two<three) {
                    four=three;
                    fourth=third;
                    three=two;
                    third=second;
                } else if (four<two) {
                    four=two;
                    fourth=second;
                }
                two=one;
                second=first;
                one=time1;
                first=num;
            } else if (time1<two) {
                if (two<three) {
                    four=three;
                    fourth=third;
                    three=two;
                    third=second;
                } else if (four<two) {
                    four=two;
                    fourth=second;
                }
                two=time1;
                second=num;
            } else if (time1<three) {
                four=three;
                fourth=third;
                three=time1;
                third=num;
            } else if (time1<two) {
                four=time1;
                fourth=num;
            }
        }
        printf("%d %.2lf\n%d %.2lf\n",first,one,second,two);
    }
    printf("%d %.2lf\n%d %.2lf\n",third,three,fourth,four);
    return 0;
}