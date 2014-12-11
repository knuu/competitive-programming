//
//  ITP1-9-C.c
//  
//
//  Created by n_knuu on 2014/03/18.
//
//

#include <stdio.h>
#include <string.h>
int main(void) {
    int ta=0,ha=0,num,i;
    char strta[101],strha[101];
    scanf("%d\n",&num);
    for (i=0; i<num; i++) {
        scanf("%s %s\n",strta,strha);
        if (strcmp(strta,strha)>0) {
            ta+=3;
        } else if (strcmp(strta,strha)<0) {
            ha+=3;
        } else {
            ta++;
            ha++;
        }
    }
    printf("%d %d\n",ta,ha);
    return 0;
}