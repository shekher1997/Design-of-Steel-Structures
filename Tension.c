#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void main(){
     int i, ch, x1, x2; float p, b, t, Tdg, Tdn, Tdb, Tdb1, Tdb2, g, B;
     float S[20][6] = {{50, 6, 568, 15.1, 9.6, 14.5}, {55, 6, 626, 16.6, 10.6, 15.7}, {55, 8, 818, 16.4, 10.6, 16.5}, {55, 10, 1002, 16.2, 10.6, 17.2}, {60, 6, 684, 18.2, 11.5, 16.9},
					  {60, 8, 896, 18, 11.5, 17.7}, {60, 10, 1100, 17.8, 11.5, 18.5}, {65, 6, 744, 19.8, 12.6, 18.1}, {65, 8, 976, 19.6, 12.5, 18.9}, {65, 10, 1200, 19.4, 12.5, 19.7},
					  {70, 6, 806, 21.4, 13.6, 19.4}, {70, 8, 1058, 21.2, 13.5, 20.2}, {70, 10, 1302, 21, 13.5, 21}, {75, 6, 866, 23, 14.6, 20.6}, {75, 8, 1138, 22.8, 14.5, 21.4}, 
					  {75, 10, 1402, 22.6, 14.5, 22.2}, {80, 8, 1221, 24.4, 15.5, 22.7}, {80, 10, 1505, 24.1, 15.5, 23.4},{80, 12, 1781, 23.9, 15.4, 24.2}, {90, 8, 1379, 27.5, 17.5, 25.1}};
    printf("Enter the load and b , t : ");
    scanf("%f%f%f", &p, &b, &t);
    printf("Enter 1 For SA and 2 For DA : ");
	scanf("%d", &ch);
    printf("Enter Weld lengths : ");
    scanf("%d%d", &x1,&x2);

    for (i = 0 ; i < 20 ; i++){
        if((S[i][0] == b) && (S[i][1] == t)){
            break;
        }
    }
    if (ch == 1)
    {
        Tdg = S[i][2] * 250 / (1.1 * 1000);
        if (Tdg < p)
        {
            printf("Section Failed, Tdg = %0.3f, P = %0.3f.\n", Tdg, p);
            exit(0);
        }
    recheck11:
        B = 1.4 - 0.076 * (b / t) * (250 / 410) * ((x1 * 2) / (x1 + x2));
        if (B < 0.7 || B > ((410 * 1.1) / (250 * 1.25)))
        {
            printf("Change Weld Size.\n");
            exit(0);
        }

        Tdn = 0.9 * (S[i][2] / 2) * (410 / 1.25) + B * (S[i][2] / 2) * (250 / 1.1);
        if (Tdn / 1000 < p)
        {
            x1 += 15;
            x2 += 15;
            goto recheck11;
        }
    }
    else if (ch == 2)
    {
        Tdg = 2*S[i][2] * 250 / (1.1 * 1000);
        if (Tdg < p)
        {
            printf("Section Failed, Tdg = %0.3f, P = %0.3f.\n", Tdg, p);
            exit(0);
        }
    recheck12:
        B = 1.4 - 0.076 * (2*b / t) * (250 / 410) * ((x1 * 2) / (x1 + x2));
        if (B < 0.7 || B > ((410 * 1.1) / (250 * 1.25)))
        {
            printf("Change Weld Size.\n");
            exit(0);
        }

        Tdn = 2*(0.9 * (S[i][2] / 2) * (410 / 1.25) + B * (S[i][2] / 2) * (250 / 1.1));
        if (Tdn / 1000 < p)
        {
            x1 += 15;
            x2 += 15;
            goto recheck12;
        }
    }

    recheck2:
    g = t + 2;
    Tdb1 = (g*x2*2*250)/(sqrt(3)*1.1) + 0.9*(b*g)*(410/1.25);
    Tdb2 = 0.9*(g*x2*2*410)/(sqrt(3)*1.25) + 0.9*(b*g)*(250/1.1);
    if (Tdb1 < Tdb2){
        Tdb = Tdb1;
    }
    else{
        Tdb = Tdb2;
    }

    if (Tdb/1000 < p){
        x1 += 15;
        x2 += 15;
        goto recheck2;
    }

    printf ("\nTdg = %0.3f, Tdn = %0.3f, Tdb = %0.3f, G = %0.1f, x1 = %d, x2 = %d.\n", Tdg, Tdn/1000, Tdb/1000, g, x1, x2);
}