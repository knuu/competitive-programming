//
//  AOJ0501.c
//  
//
//  Created by n_knuu on 2014/03/05.
//
//

#include <stdio.h>
#include <string.h>
int main(void) {
    int cnum,snum,i;
    char dic[62],be,af,str;
    while (1) {
        scanf("%d\n",&cnum);
        if (cnum==0) break;
        for (i=0; i<62; i++) dic[i]='.';
        for (i=0; i<cnum; i++) {
            scanf("%c %c\n",&be,&af);
            if (isdigit(be)!=0) {
                dic[be-'0']=af;
            } else if (islower(be)!=0) {
                dic[be-'a'+10]=af;
            } else {
                dic[be-'A'+36]=af;
            }
        }
        scanf("%d\n",&snum);
        for (i=0; i<snum; i++) {
            scanf("%c\n",&str);
            if (isdigit(str)!=0) {
                if(dic[str-'0']!='.') str=dic[str-'0'];
            } else if (islower(str)!=0) {
                if(dic[str-'a'+10]!='.') str=dic[str-'a'+10];
            } else if (isupper(str)!=0) {
                if(dic[str-'A'+36]!='.') str=dic[str-'A'+36];
            }
            printf("%c",str);
        }
        printf("\n");
    }
    return 0;
}