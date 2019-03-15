#include<stdio.h>
#include<math.h>

void main(){
    float b, t, cg, wmin, wmax, w, area, str, lt, x1, x2, p; int i, n, k;
    float S[20][6] = {{50, 6, 568, 15.1, 9.6, 14.5}, {55, 6, 626, 16.6, 10.6, 15.7}, {55, 8, 818, 16.4, 10.6, 16.5}, {55, 10, 1002, 16.2, 10.6, 17.2}, {60, 6, 684, 18.2, 11.5, 16.9},
					  {60, 8, 896, 18, 11.5, 17.7}, {60, 10, 1100, 17.8, 11.5, 18.5}, {65, 6, 744, 19.8, 12.6, 18.1}, {65, 8, 976, 19.6, 12.5, 18.9}, {65, 10, 1200, 19.4, 12.5, 19.7},
					  {70, 6, 806, 21.4, 13.6, 19.4}, {70, 8, 1058, 21.2, 13.5, 20.2}, {70, 10, 1302, 21, 13.5, 21}, {75, 6, 866, 23, 14.6, 20.6}, {75, 8, 1138, 22.8, 14.5, 21.4}, 
					  {75, 10, 1402, 22.6, 14.5, 22.2}, {80, 8, 1221, 24.4, 15.5, 22.7}, {80, 10, 1505, 24.1, 15.5, 23.4},{80, 12, 1781, 23.9, 15.4, 24.2}, {90, 8, 1379, 27.5, 17.5, 25.1}};

    printf("Enter the load and b , t : ");
    scanf("%f%f%f", &p, &b, &t);
    if (t <= 10)
        wmin = 3;
    if (t > 10)
        wmin = 5;
    for (i = 0 ; i < 20 ; i++){
        if((S[i][0] == b) && (S[i][1] == t)){
            cg = S[i][5];
            wmax = (3*t)/4;
            //printf("%f", wmax);
            break;
        }
    }
    w = ceil((wmin + wmax)/2);
    if (w > wmax)
        w = wmax - 1;
    area = .707*w; 
    str = area*410/(sqrt(3)*1.25*1000);
    lt = ceil(p/str);
    x1 = (lt*cg)/b;
    x2 = lt - x1;

    printf("\n  C.G. = %0.3f. \n  Wmax = %0.3f. \n  Wmin = %0.3f. \n  W = %0.3f. \n  Total weld length = %0.3f.\n  X = %0.3f. \n  %0.1f - X = %0.3f.\n\n", cg, wmax, wmin, w, lt, x1, lt, x2);
}