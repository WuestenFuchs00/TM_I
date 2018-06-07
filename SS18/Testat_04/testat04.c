/**
 * Technische Mechanik I (MW SoSe 2018)
 *
 * Testat 4 (Hinweis: Ritterschnittverfahren)
 *
 * Compile:  gcc -Wall -std=gnu99 -pedantic <datei.c> -lm -o <datei>
 *
 * Option -lm wird verwendet, um Bibliothek <math.h> einzubinden.
 */
#include <stdio.h>
#include <math.h>

int main () {
  
  //Variableninitialisierung
  double a, b, c , h; // [m]
  double F1, F2; // [kN]
  
  double d = 0; // [m]
  double alpha = 0; // Winkel, [rad]
  double FB = 0, FA = 0; // vertikale Lagerreaktionen, [N]
  double FS1 = 0; // Stabkraft, [N]
  
  //Einlesen von Werte
  printf("\na in [m]: ");
  scanf("%lf", &a);
  
  printf("\nb in [m]: ");
  scanf("%lf", &b);
  
  printf("\nc in [m]: ");
  scanf("%lf", &c);
  
  printf("\nh in [m]: ");
  scanf("%lf", &h);
  
  printf("\nF1 in [kN]: ");
  scanf("%lf", &F1);
  
  printf("\nF2 in [kN]: ");
  scanf("%lf", &F2);
  
  //Berechne d
  d = (b-c)*0.5;
  
  //Berechne Winkel alpha
  alpha = atan(h/d);
  
  //Umrechne F1 und F2 in [N]
  F1 *= 1000;
  F2 *= 1000;
  
  //Berechne (vertikale) Lagerreaktionen FB und FA
  FB = (F2*(3*a+c+d)-F1*(3*a-d))/b;
  FA = F1+F2-FB;
  
  //Berechne Stabkraft FS1
  FS1 = -FA*b/(b*sin(alpha));
  
  printf("\nFS1 = %.1lf [N]\n", FS1);
  
  return 0;
}
