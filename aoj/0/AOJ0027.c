//
//  AOJ0027.c
//  
//
//  Created by n_knuu on 2014/02/22.
//
//

#include <stdio.h>
int main(void){
    int i=0,j,k,sum,n,month[100],date[100],md[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    while(1){
        scanf("%d %d",&month[i],&date[i]);
        if(month[i]==0) break;
        i++;
    }
    for(j=0;j<i;j++){
        sum=0;
        for(k=0;k<month[j]-1;k++) sum+=md[k];
        sum+=date[j];
        n=sum%7;
        switch (n) {
            case 1:
                printf("Thursday\n");
                break;
            case 2:
                printf("Friday\n");
                break;
            case 3:
                printf("Saturday\n");
                break;
            case 4:
                printf("Sunday\n");
                break;
            case 5:
                printf("Monday\n");
                break;
            case 6:
                printf("Tuesday\n");
                break;
            case 0:
                printf("Wednesday\n");
                break;
                
        }
    }
    return 0;
}