/**
 * Technische Mechanik I (MW SoSe 2018)
 *
 * Testat 2
 *
 * Compile:  gcc -Wall -std=gnu99 -pedantic <datei.c> -lm -o <datei>
 *
 * Option -lm wird verwendet, um Bibliothek <math.h> einzubinden.
 */
#include <stdio.h>
#include <math.h>

int main () {
  
  // Variableninitialisierung
  const double g = 9.81; // Beschleunigung [m/s^2]  
    
  double alpha; // Winkelmass [rad]
  double l1, l2, d; // Laengen in [m]
  double m; // Masse [kg]
  double X = 0, FB = 0;
  
  //Einlesen der Werte
  printf("Winkel alpha: "); // [rad]
  if ( scanf("%lf", &alpha) == 0 ) {
	printf("Ungueltige Eingabe!\n");
	return 1;
  }
  
  printf("Laenge l1: "); // [m]
  if ( scanf("%lf", &l1) == 0 ) {
	printf("Ungueltige Eingabe!\n");
	return 1;
  }
  
  printf("Laenge l2: "); // [m]
  if ( scanf("%lf", &l2) == 0 ) {
	printf("Ungueltige Eingabe!\n");
	return 1;
  }
  
  printf("Dicke d: "); // [m]
  if ( scanf("%lf", &d) == 0 ) {
	printf("Ungueltige Eingabe!\n");
	return 1;
  }
  
  printf("Masse m: "); // [kg]
  if ( scanf("%lf", &m) == 0 ) {
	printf("Ungueltige Eingabe!\n");
	return 1;
  }
  
  //Berechnen von X:=sin(alpha)*cos(alpha)*l2
  X = sin(alpha) * cos(alpha) * l2;
  
  //Berechnen von Kraft FB
  FB = m * g / (d*cos(alpha));
  FB *= ((l1*cos(alpha)+d)*pow(cos(alpha),2)-d-X);
  
  printf("\nKraft F_B betraegt: %.1lf\n", FB);
  
  return 0;
}
