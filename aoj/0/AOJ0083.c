//
//  AOJ0083.c
//  
//
//  Created by n_knuu on 2014/02/24.
//
//

#include <stdio.h>
int main(void){
    int year,month,date;
    while (scanf("%d %d %d",&year,&month,&date)!=EOF) {
        if (year<1868||(year==1868&&(month<9||(month==9&&date<8)))) {
            printf("pre-meiji\n");
        } else if (year<1912||(year==1912&&(month<7||(month==7&&date<30)))) {
            printf("meiji %d %d %d\n",year-1867,month,date);
        } else if (year<1926||(year==1926&&(month<12||(month==12&&date<25)))) {
            printf("taisho %d %d %d\n",year-1911,month,date);
        } else if (year<1989||(year==1989&&(month<1||(month==1&&date<8)))) {
            printf("showa %d %d %d\n",year-1925,month,date);
        } else {
            printf("heisei %d %d %d\n",year-1988,month,date);
        }
    }
    return 0;
}