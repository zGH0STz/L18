// 180.c Sagatave funkcijas integrēšanai ar taisnstūru metodi
// Elvijs buls

#include <stdio.h>
#include <math.h>

double f1 (double x){ // Lietotāja pētāmā funkcija
	return 2*x;
}

int main(){

	int k; // Iterācijas numurs pēc kārtas

	double a = -2, b = 2, I1 = 0., I2, h; // a, b – argumentu intervāls
								// I1 – iepriekšējais Integrālis,
								// I2 – tekošais Integrālis, kur 'eps' ir rezultāta
	double eps=0.0001;			 // precizitāte angliski saukta "varepsilon"
	long int n = 1;


	I2 = (b-a) * ( f1(a) + f1(b) ) / 2; // Tādā veidā aprēķina integrāļa tuvinājumu

	while ( fabs(I2-I1) > eps){ // Tādā veidā, salīdzinot funkcijas summas tekošās
		n=n*2; 					// vērtības precizitāti ar pieļaujamo eps vērtību,
		h=(b-a)/n; 				// palielina intervālu skaitu 2 reizes,
		I1=I2; 					// nosaka intervāla platuma vērtību, saglabā tekošo vērtību mainīgajā I1
		I2=0;					// Tekošā summas (integrāļa) vērtība tiek nonullēta

		for (k=0;k < n;k++){
			I2 = I2 + h * f1(a + (k + .5) * h); // Summa no visiem laukumiņiem dod integrāļa tuvināto vērtību
		}
}
printf("Dotās funkcijas izteiksme: f(x) = 2x \n");
printf("Argumentu a un b vērtības: a = %.4lf, b = %.4lf \n", a, b);
printf("Funkcijas noteiktā integrāļa vērtība I = %.4lf \n", I2);
printf("Taisnstūru skaits N = %ld pēc argumentu intervāla dalīšanas N daļās.\n", n);
// Izvadam rezultātus gadījumā, ja divu aprēķināto
// integrāļu vērtības ir tik tuvas, ka ir mazākas
// par mainīgā 'eps' vērtību.

}
