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
  double y1 = 0.0, y2 = 0.0, ys = 0.0, A1 = 0.0, A2 = 0.0;
  
  //Einlesen von Werten b und R
  printf("Eingabe Abstand b : ");
  scanf("%lf", &b);
  
  printf("Eingabe Radius R : ");
  scanf("%lf", &R);
  
  //Berechnen der Terme
  alpha = acos(1-(b/R));
  sinAlpha = sin(alpha);
  
  A2 = alpha*R*R-sinAlpha*(R-b)*R;
  A1 = R*R*PI-A2;
  
  y2 = ((0.5*R*R*R*(2*alpha-4.0*sinAlpha/3.0)-(R+2*b)*(R-b)*R*sinAlpha/3.0));
  y1 = (R*R*R*PI - y2);
  
  //Berechnen des Schwerpunkts
  ys = rho1 * y1 + rho2 * y2;
  ys /= ((rho1 * A1) + (rho2 * A2));
  
  //Ausgabe des Ergebnises
  printf("Schwerpunkt ys : %.2lf", ys);
  
  return 0;
}
