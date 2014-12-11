//
//  AOJ0101.c
//  
//
//  Created by n_knuu on 2014/03/18.
//
//

#include <stdio.h>
#include <string.h>
int main(void) {
    int num,i;
    char string[1002],*check;
    scanf("%d\n",&num);
    for (i=0; i<num; i++) {
        fgets(string,sizeof(string),stdin);
        while ((check=strstr(string,"Hoshino"))!=NULL) check[6]='a';
        printf("%s",string);
    }
    return 0;
}