//
//  AOJ1137.c
//  
//
//  Created by knuu on 2014/05/18.
//
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
int alpha(char a);
int toarabic(char roman[]);
void toroman(int arabic);
int main(void) {
    int num,result,i;
    char op1[9],op2[9];
    scanf("%d",&num);
    for (i=0; i<num; i++) {
        result = 0;
        scanf(" %s %s",op1,op2);
        result = toarabic(op1) + toarabic(op2);
        toroman(result);
    }
    return 0;
}

int alpha(char a) {
    switch (a) {
        case 'm':
            return 1000;
        case 'c':
            return 100;
        case 'x':
            return 10;
        case 'i':
            return 1;
    }
}

int toarabic(char roman[]) {
    int i,result=0;
    for (i=0; i<strlen(roman); i++) {
        if (isalpha(roman[i])) {
            result+=alpha(roman[i]);
        } else {
            result+= (roman[i]-'0') * alpha(roman[i+1]);
            i++;
        }
    }
    return result;
}

void toroman(int arabic) {
    if (arabic/1000==1) {
        printf("m");
    } else if (arabic/1000>1) {
        printf("%dm",arabic/1000);
    }
    arabic%=1000;
    
    if (arabic/100==1) {
        printf("c");
    } else if (arabic/100>1) {
        printf("%dc",arabic/100);
    }
    arabic%=100;
    
    if (arabic/10==1) {
        printf("m");
    } else if (arabic/10>1) {
        printf("%dm",arabic/10);
    }
    arabic%=10;
    
    if (arabic/1==1) {
        printf("m");
    } else if (arabic/1>1) {
        printf("%dm",arabic/1);
    }
    arabic%=1;
    
    printf("\n");
}