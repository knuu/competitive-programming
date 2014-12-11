//
//  AOJ0115.c
//  
//
//  Created by n_knuu on 2014/03/06.
//
//

#include <stdio.h>

int det(int a11,int a12,int a13,int a21,int a22,int a23,int a31,int a32,int a33);

int main(void) {
    int xo,yo,zo,xe,ye,ze,x1,y1,z1,x2,y2,z2,x3,y3,z3,detA,dets,dett,detk;
    double s,t,k;
    scanf("%d %d %d\n%d %d %d\n%d %d %d\n%d %d %d\n%d %d %d\n",&xo,&yo,&zo,&xe,&ye,&ze,&x1,&y1,&z1,&x2,&y2,&z2,&x3,&y3,&z3);
    detA=det(-x1+x2,-x1+x3,-xe+xo,-y1+y2,-y1+y3,-ye+yo,-z1+z2,-z1+z3,-ze+zo);
    dets=det(-x1+xo,-x1+x3,-xe+xo,-y1+yo,-y1+y3,-ye+yo,-z1+zo,-z1+z3,-ze+zo);
    dett=det(-x1+x2,-x1+xo,-xe+xo,-y1+y2,-y1+yo,-ye+yo,-z1+z2,-z1+zo,-ze+zo);
    detk=det(-x1+x2,-x1+x3,-x1+xo,-y1+y2,-y1+y3,-y1+yo,-z1+z2,-z1+z3,-z1+zo);
    s=1.0*dets/detA;
    t=1.0*dett/detA;
    k=1.0*detk/detA;
    if (k>0.0&&k<=1.0&&s>=0.0&&t>=0.0&&s+t<=1.0) {
        printf("MISS\n");
    } else {
        printf("HIT\n");
    }
    return 0;
}

int det(int a11,int a12,int a13,int a21,int a22,int a23,int a31,int a32,int a33) {
    return a11*a22*a33+a12*a23*a31+a13*a21*a32-a11*a23*a32-a12*a21*a33-a13*a22*a31;
}