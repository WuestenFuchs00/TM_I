/**
 * Technische Mechanik TM1 (WS2018)
 * Uebungsblatt 1 - E-Test 1
 *
 * Compile:
 *	gcc -Wall -std=gnu99 -pedantic <File.c> -o <File> -lm
 *
 * Option -lm is needed to link the math functions from <mth.h>.
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

	double F, Ax = 0; // Kraft
	double a; // Winkel

	printf("\nKraft F (Einheit kN): ");
	scanf("%lf", &F);

	printf("\nWinkel a (Einheit Grad °): ");
	scanf("%lf", &a);

	printf("\nGegeben: F = %.2lf kN", F);
	printf("\n         a = %.2lf °\n", a);

	// Umrechnen von Winkeln a, b, c vom GRAD nach RADIAN
	a *= _PI / 180.0;

	// Berechnen der Kraft Ax
	Ax = (sin(a) - cos(a) - 1) * F;

	printf("\nGesuchte horizontale Kraft am Auflage:");
	printf("\n  Ax = %.1lf kN\n", Ax);

	return 0;
}
