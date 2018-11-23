/**
 * Technische Mechanik TM1 (WS2018)
 * E-Test 2
 *
 * Compile:
 *		gcc -Wall -std=gnu99 -pedantic <File.c> -o <File> -lm
 *
 * Option -lm is needed to link the math functions from <math.h>.
 */
#include <stdio.h>
#include <math.h>

/*
 * Convert a degree value to a radian value.
 * Example: d = 90° (degree) == 90° * PI / 180° = 0.5 * PI
 *
 * Params:
 * 	d : Value in degree
 *
 * Return:
 *	Value in radian
 */
//double DegToRad (double d) { return d * _PI / 180; }

int main (int argc, char* argv[])
{
	const double _PI = 3.14159265358979323846;
	
	double F1, F2; // externe Kraefte
	double Alpha; // Winkel
	
	double Ah = 0, Av = 0, Bv = 0; // Lagerkraefte
	double S1 = 0; // Stabkraft

	printf("\nKraft F1 (Einheit kN): ");
	scanf("%lf", &F1);
	
	printf("\nKraft F2 (Einheit kN): ");
	scanf("%lf", &F2);

	printf("\nWinkel Alpha (Einheit Grad °): ");
	scanf("%lf", &Alpha);

	printf("\nGegeben: F1    = %.2lf kN", F1);
	printf("\n         F2    = %.2lf kN", F2);
	printf("\n         Alpha = %.2lf °\n", Alpha);

	// Umrechnen von Winkeln a, b, c vom GRAD nach RADIAN
	Alpha *= _PI / 180.0;

	// Berechnung der Lagerkraefte
	Ah = F1;
	Av = 0.5 * F2 + tan(Alpha) * 0.25 * F1;
	Bv = 0.5 * F2 - tan(Alpha) * 0.25 * F1;
	
	// Berechnung der Stabkraft S1
	S1 = -0.25 * F1 + ( F2 / (2 * tan(Alpha)) );
	
	printf("\nErgebnis:");
	printf("\n   Auflagerkraefte:");
	printf("\n      Ah = %.1lf", Ah);
	printf("\n      Av = %.1lf", Av);
	printf("\n      Bv = %.1lf", Bv);
	printf("\n   Stabkraft S1:");
	if ( S1 >= 0 ) {
		printf("\n      S1 = +%.1lf\n", S1);
	} else {
		printf("\n      S1 = -%.1lf\n", S1);
	}	
	return 0;
}
