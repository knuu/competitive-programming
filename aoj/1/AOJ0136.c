//
//  AOJ0136.c
//  
//
//  Created by n_knuu on 2014/03/09.
//
//

#include <stdio.h>
int main(void) {
    int num,i,j,count[6]={0};
    double height;
    scanf("%d",&num);
    for (i=0; i<num; i++) {
        scanf("%lf",&height);
        if (height<165.0) {
            count[0]++;
        } else if (height<170.0) {
            count[1]++;
        } else if (height<175.0) {
            count[2]++;
        } else if (height<180.0) {
            count[3]++;
        } else if (height<185.0) {
            count[4]++;
        } else {
            count[5]++;
        }
    }
    for (i=0; i<6; i++) {
        printf("%d:",i+1);
        for (j=0; j<count[i]; j++) printf("*");
        printf("\n");
    }
    return 0;
}