//
//  AOJ0280.c
//  
//
//  Created by knuu on 2014/05/02.
//
//

#include <stdio.h>
int main(void) {
    int num,i,j,place,key;
    char card[101];
    while (scanf("%d",&num)!=EOF&&num!=0) {
        int count[10]={0};
        scanf(" %s",card);
        place=0;
        for (i=0; i<100; i++) {
            switch (card[i]) {
                case 'M':
                    count[i%num]++;
                    break;
                case 'S':
                    place+=count[i%num]+1;
                    count[i%num]=0;
                    break;
                case 'L':
                    count[i%num]+=place+1;
                    place=0;
                    break;
            }
        }
        for (i=0; i<num; i++) {
            for (j=0; j<num-i-1; j++) {
                if (count[j]>count[j+1]) {
                    key=count[j];
                    count[j]=count[j+1];
                    count[j+1]=key;
                }
            }
        }
        for (i=0; i<num; i++) {
            if (i) printf(" ");
            printf("%d",count[i]);
        }
        printf(" %d\n",place);
    }
    return 0;
}