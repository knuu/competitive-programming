//
//  AOJ0123.c
//  
//
//  Created by n_knuu on 2014/03/19.
//
//

#include <stdio.h>
int main(void) {
    double hkm,km;
    while (scanf("%lf %lf",&hkm,&km)!=EOF) {
        if (hkm<35.5&&km<71.0) {
            printf("AAA\n");
        } else if (hkm<37.5&&km<77.0) {
            printf("AA\n");
        } else if (hkm<40.0&&km<83.0) {
            printf("A\n");
        } else if (hkm<43.0&&km<89.0) {
            printf("B\n");
        } else if (hkm<50.0&&km<105.0) {
            printf("C\n");
        } else if (hkm<55.0&&km<116.0) {
            printf("D\n");
        } else if (hkm<70.0&&km<148.0) {
            printf("E\n");
        } else {
            printf("NA\n");
        }
    }
    return 0;
}