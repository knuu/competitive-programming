//
//  AOJ0038.c
//  
//
//  Created by n_knuu on 2014/02/26.
//
//

#include <stdio.h>
int main (void) {
    int temp[5],card[14],i,one,two,three,four;
    while (scanf("%d,%d,%d,%d,%d\n",&temp[0],&temp[1],&temp[2],&temp[3],&temp[4])!=EOF) {
        one=0;
        two=0;
        three=0;
        four=0;
        for(i=1;i<=13;i++) card[i]=0;
        for (i=0; i<5; i++) {
            card[temp[i]]++;
            if (card[temp[i]]==1) one++;
            if (card[temp[i]]==2) {
                one--;
                two++;
            }
            if (card[temp[i]]==3) {
                two--;
                three++;
            }
            if (card[temp[i]]==4) {
                three--;
                four++;
            }
        }
        if (four==1) {
            printf("four card\n");
        } else if (three==1&&two==1) {
            printf("full house\n");
        } else if (one==5) {
            for (i=1;i<=10;i++) {
                if (i<=9&&card[i]==1&&card[i+1]==1&&card[i+2]==1&&card[i+3]==1&&card[i+4]==1) {
                    printf("straight\n");
                    break;
                } else if (i==10&&card[i]==1&&card[i+1]==1&&card[i+2]==1&&card[i+3]==1&&card[1]==1) {
                    printf("straight\n");
                    break;
                } else if (i==10) {
                    printf("null\n");
                    break;
                }
            }
        } else if (three==1) {
            printf("three card\n");
        } else if (two==2) {
            printf("two pair\n");
        } else if (two==1) {
            printf("one pair\n");
        } else {
            printf("null\n");
        }
    }
    return 0;
}