#include <stdio.h>
#include <math.h>

/* The following program is only applicable for Angle Section under compression load */

void main()
{
	float lamvv, lamphi, lam, phi, fcd, pd, klr, p;
	int i, ch, k, La;
	// S stands for Specification 
	// First Col b
	// Second Col t
	// Third Col A
	// Fourth Col rxx
	// Fifth Col rvv
	float S[20][5] = {{50, 6, 568, 15.1, 9.6}, {55, 6, 626, 16.6, 10.6}, {55, 8, 818, 16.4, 10.6}, {55, 10, 1002, 16.2, 10.6}, {60, 6, 684, 18.2, 11.5},
					  {60, 8, 896, 18, 11.5}, {60, 10, 1100, 17.8, 11.5}, {65, 6, 744, 19.8, 12.6}, {65, 8, 976, 19.6, 12.5}, {65, 10, 1200, 19.4, 12.5},
					  {70, 6, 806, 21.4, 13.6}, {70, 8, 1058, 21.2, 13.5}, {70, 10, 1302, 21, 13.5}, {75, 6, 866, 23, 14.6}, {75, 8, 1138, 22.8, 14.5}, 
					  {75, 10, 1402, 22.6, 14.5}, {80, 8, 1221, 24.4, 15.5}, {80, 10, 1505, 24.1, 15.5},{80, 12, 1781, 23.9, 15.4}, {90, 8, 1379, 27.5, 17.5}};

	printf("Enter 1 For SA and 2 For DA : ");
	scanf("%d", &ch);
	printf("Enter P & L: ");
	scanf("%f%d", &p, &La);
	for (k = 0; k < 20; k++)
	{

		if (ch == 1)
		{
			lamvv = (La / S[k][4]) / 88.85766;
			lamphi = (S[k][0] / S[k][1]) / 88.85766;
			lam = sqrt(0.7 + 0.6 * lamvv * lamvv + 5 * lamphi * lamphi);
			klr = 0.85 * La / S[k][4];
			phi = 0.5 * (1 + 0.49 * (lam - 0.2) + lam * lam);
			fcd = (250 / 1.1) / (phi + sqrt(phi * phi - lam * lam));
			pd = (fcd * S[k][2]) / 1000;
		}
		else if (ch == 2)
		{
			lam = sqrt((250 * (0.775 * La / S[k][3]) * (0.775 * La / S[k][3])) / 1973920.88);
			klr = 0.775 * La / S[k][3];
			phi = 0.5 * (1 + 0.49 * (lam - 0.2) + lam * lam);
			fcd = (250 / 1.1) / (phi + sqrt(phi * phi - lam * lam));
			pd = (fcd * 2 * S[k][2]) / 1000;
		}

		

		if (pd > p)
		{
			printf(" B = %0.1f,    T = %0.1f,    A = %0.3f,     2A = %0.3f,   Pd = %0.3f,    KL/r = %0.3f,    L = %d.\n\n", S[k][0], S[k][1], S[k][2], 2*S[k][2], pd, klr, La);
		}
	}
}