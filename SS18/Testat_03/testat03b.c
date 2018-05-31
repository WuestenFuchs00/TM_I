/**
 * Technische Mechanik I (MW SoSe 2018)
 *
 * Testat 3
 *
 * Compile:  gcc -Wall -std=gnu99 -pedantic <datei.c> -lm -o <datei>
 *
 * Option -lm wird verwendet, um Bibliothek <math.h> einzubinden.
 */
#include <stdio.h>
#include <math.h>

int main () {
  
  //Variableninitialisierung
  const double PI = 3.14159265358979323846;
  const double rho1 = 7850; // Dichte [kg/m^3]
  const double rho2 = 2710;
  
  double b; // Abstand x-Achse zur Trennlinie
  double R; // Radius [m]
  
  double alpha = 0.0; // Winkel in [RAD]
  double sinAlpha = 0.0; // Sinus(alpha)
  double ys = 0.0;
  
  //Einlesen von Werten b und R
  printf("Eingabe Abstand b : ");
  scanf("%lf", &b);
  
  printf("Eingabe Radius R : ");
  scanf("%lf", &R);
  
  //Berechnen der Terme
  alpha = acos(1-(b/R));
  sinAlpha = sin(alpha);
  
  //Berechnen des Schwerpunkts
  ys = rho1*R*R*R*PI;
  ys += (rho2-rho1)*(R*R*R*(alpha-2.0*sinAlpha/3.0)-R*(R-b)*(R+2*b)*sinAlpha/3.0);
  ys /= R*R*(rho1*(PI-alpha+sinAlpha)+rho2*alpha)-R*sinAlpha*(rho1*b+rho2*(R-b)); 
  
  //Ausgabe des Ergebnises
  printf("Schwerpunkt ys : %.2lf\n", ys);
  
  return 0;
}
