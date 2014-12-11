//
//  AOJ0015.c
//  
//
//  Created by n_knuu on 2014/03/12.
//
//

#include <stdio.h>
#include <string.h>
int main(void) {
    int big1[79],num,i,flag;
    char number1[1024],number2[1024];
    scanf("%d\n",&num);
    for (i=0; i<num; i++) {
        scanf("%s\n",number1);
        scanf("%s\n",number2);
        if (strlen(number1)>80||strlen(number2)>80) {
            printf("overflow\n");
            continue;
        }
        for (i=0; i<strlen(number1); i++) {
            big1[i]=number1[strlen(number1)-i-1]-'0';
            big2[i]=number2[strlen(number2)-i-1]-'0';
        }
        for (<#initialization#>; <#condition#>; <#increment#>) {
            <#statements#>
        }
    }
}