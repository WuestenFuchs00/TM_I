/**
 * Technische Mechanik TM1 (WS2018)
 * Uebungsblatt 1 - Aufgabe 1.2
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

	double G, F, Fl = 0, Fr = 0; // Kraft
	double a, b, c; // Winkel
	double tanC; // Tangens von c

	printf("\nGewicht G (Einheit N): ");
	scanf("%lf", &G);

	printf("Kraft F (Einheit N): ");
	scanf("%lf", &F);

	printf("Winkel a zwischen Kraft F und der Horizontalen (Einheit Grad °): ");
	scanf("%lf", &a);

	printf("Winkel b zwischen Kraft Fl und der Horizontalen (Einheit Grad °): ");
	scanf("%lf", &b);

	printf("Winkel c zwischen Kraft Fr und der Horizontalen (Einheit Grad °): ");
	scanf("%lf", &c);

	printf("\nGegeben: G = %.2lf N, F = %.2lf N\n", G, F);
	printf("         a = %.2lf°, b = %.2lf°, c = %.2lf°\n", a, b, c);

	// Umrechnen von Winkeln a, b, c vom GRAD nach RADIAN
	a *= _PI / 180.0;
	b *= _PI / 180.0;
	c *= _PI / 180.0;

	// Berechnen der Kräfte Fl und Fr
	tanC = sin(c) / cos(c);
	Fl = (G + F * (sin(a) - tanC * cos(a))) / (sin(b) + tanC * cos(b));
	Fr = (F * cos(a) + Fl * cos(b)) / cos(c);

	printf("\n1. Gesuchte Kräfte Fl und Fr sind:");
	printf("\n  Fl = %.1lf N", Fl);
	printf("\n  Fr = %.1lf N\n", Fr);

	// Neuberechnen von F, wenn die Walze aus der Führung geraten soll
	F = (-1) * G / (sin(a) - tanC * cos(a));
	printf("\n2. F darf höchstens anwachsen auf:");
	printf("\n  F = %1.lf N\n", F);
	printf("d.h. wenn Fl = 0 gilt.\n");

	return 0;
}
